#include "registrationwindow.h"
#include "authorization_menu.h"
#include "regerrhandler.h"
#include "regstylehelper.h"
#include "stylehelper.h"

RegistrationWindow::RegistrationWindow(QWidget *parent)
    : QMainWindow{parent}
{
    StyleHelper *helper = new RegStyleHelper();

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setStyleSheet("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(57, 255, 203, 255), stop:1 rgba(255, 209, 52, 255))");
    centralWidget->setMinimumSize(800, 600);

    centralLayout = new QVBoxLayout(centralWidget);
    registrationBox = new QGroupBox();
    registrationBox->setFixedSize(320, 360);
    registrationBox->setStyleSheet(helper->getBoxStyle() + helper->getLinesStyle() + helper->getButtonsStyle() + helper->getLabelsStyle() + RegStyleHelper::getComboBoxStyle());

    centralLayout->addWidget(registrationBox);
    centralLayout->setAlignment(registrationBox, Qt::AlignCenter);

    registrationBoxLayout = new QVBoxLayout(registrationBox);

    linesHorizontalLayout = new QHBoxLayout*[7];
    for(int i = 0; i < 7; i++)
        linesHorizontalLayout[i] = new QHBoxLayout();

    arrayLabel = new QLabel*[7];
    for(int i = 0; i < 7; i++)
    {
        arrayLabel[i] = new QLabel();
        //arrayLabel[i]->setStyleSheet(helper->getLabelsStyle());
    }

    arrayLabel[0]->setText("Имя");
    arrayLabel[1]->setText("Фамилия");
    arrayLabel[2]->setText("Отчество");
    arrayLabel[3]->setText("Номер");
    arrayLabel[4]->setText("Почта");
    arrayLabel[5]->setText("Пароль");
    arrayLabel[6]->setText("Роль");

    for(int i = 0; i < 7; i++)

    arrayLine = new QLineEdit*[6];
    for(int i = 0; i < 6; i++)
    {
        arrayLine[i] = new QLineEdit();
    }

    roleField = new QComboBox();

    roleField->setStyleSheet("color: black");
    roleField->addItem("Преподаватель");
    roleField->addItem("Студент");

    for(int i = 0; i < 7; i++)
        linesHorizontalLayout[i]->addWidget(arrayLabel[i]);
    for(int i = 0; i < 6; i++)
        linesHorizontalLayout[i]->addWidget(arrayLine[i]);


    linesHorizontalLayout[6]->addWidget(roleField);

    for(int i = 0; i < 7; i++)
        registrationBoxLayout->addLayout(linesHorizontalLayout[i]);

    registrationButton = new AnimatedButton("Зарегистрироваться");
    registrationBoxLayout->addWidget(registrationButton);

    for(int i = 0; i < 6; i++)
        if(i != 2)
        {
            connect(arrayLine[i], &QLineEdit::textChanged, this, &RegistrationWindow::updateRegistrationButtonState);
        }

    connect(registrationButton, &QPushButton::clicked, this, &RegistrationWindow::onRegistrationButtonClicked);
}

RegistrationWindow::~RegistrationWindow()
{
    delete centralWidget;
}

void RegistrationWindow::onRegistrationButtonClicked()
{
    std::string *values = new std::string[7];

    for(int i = 0; i < 6; i++)
        values[i] = arrayLine[i]->text().toStdString();

    if(roleField->currentText().toStdString() == "Преподаватель")
        values[6] = "MENTOR";
    else
        values[6] = "STUDENT";

    RegErrHandler handler;

    if(handler.handleException(arrayLine[0], handler.getNameExp()) &&
        handler.handleException(arrayLine[1], handler.getNameExp()) &&
        handler.handleException(arrayLine[2], handler.getNameExp()) &&
        handler.handleException(arrayLine[3], handler.getPhoneNumExp()) &&
        handler.handleException(arrayLine[4], handler.getEmailExp()))
        AuthorizationMenu::registration(values);
    delete[] values;
}

void RegistrationWindow::updateRegistrationButtonState()
{
    if(!arrayLine[0]->text().isEmpty() &&
       !arrayLine[1]->text().isEmpty() &&
       !arrayLine[3]->text().isEmpty() &&
       !arrayLine[4]->text().isEmpty() &&
       !arrayLine[5]->text().isEmpty())
        registrationButton->setEnabled(true);
    else
        registrationButton->setEnabled(false);
}
