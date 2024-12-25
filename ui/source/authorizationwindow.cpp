#include "authorizationwindow.h"
#include "authorization_menu.h"
#include "mentorwindow.h"
#include "studentwindow.h"
#include "registrationwindow.h"
#include "stylehelper.h"

#include <QStyleOption>
#include <QPropertyAnimation>
#include <QFocusEvent>
#include <QMessageBox>

AuthorizationWindow::AuthorizationWindow(QWidget *parent)
    : QMainWindow{parent}
{
    StyleHelper obj;
    StyleHelper *helper = &obj;

    mentor = nullptr;
    student = nullptr;

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    centralWidget->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(138, 33, 182, 255), stop:1 rgba(47, 164, 188, 255))");
    centralWidget->setMinimumSize(800, 600);

    windowLayout = new QVBoxLayout(centralWidget);

    authorizationBox = new QGroupBox();
    authorizationBox->setFixedSize(320, 360);
    authorizationBox->setStyleSheet(helper->getLinesStyle() + helper->getBoxStyle() + helper->getLabelsStyle());

    windowLayout->addWidget(authorizationBox);
    windowLayout->setAlignment(authorizationBox, Qt::AlignCenter);

    authorizationButton = new AnimatedButton("Авторизоваться");
    authorizationButton->setStyleSheet(helper->getButtonsStyle());
    authorizationButton->setEnabled(false);

    connect(authorizationButton, &QPushButton::clicked, this, &AuthorizationWindow::onAuthorizationButtonClicked);

    verticalLayout = new QVBoxLayout(authorizationBox);

    emailHorizontalLayout = new QHBoxLayout();
    passwordHorizontalLayout = new QHBoxLayout();

    verticalLayout->addLayout(emailHorizontalLayout);
    verticalLayout->addLayout(passwordHorizontalLayout);
    verticalLayout->addWidget(authorizationButton);

    emailLabel = new QLabel ("Эл. почта");

    passwordLabel = new QLabel ("Пароль");

    emailLine = new MyLineEdit();
    connect(emailLine, &QLineEdit::textChanged, this, &AuthorizationWindow::updateAuthorizationButtonState);

    passwordLine = new MyLineEdit();
    connect(passwordLine, &QLineEdit::textChanged, this, &AuthorizationWindow::updateAuthorizationButtonState);

    emailHorizontalLayout->addWidget(emailLabel);
    emailHorizontalLayout->addWidget(emailLine);

    passwordHorizontalLayout->addWidget(passwordLabel);
    passwordHorizontalLayout->addWidget(passwordLine);

    registrationLabel = new ClickableLabel("Регистрация");
    registrationLabel->setFixedSize(74, 20);
    connect(registrationLabel, &ClickableLabel::clicked, this, &AuthorizationWindow::replaceWithRegistrationWindow);

    registerLabelLayout = new QVBoxLayout();
    registerLabelLayout->addWidget(registrationLabel, 0, Qt::AlignHCenter | Qt::AlignBottom);

    verticalLayout->addLayout(registerLabelLayout);

    betweenEmail = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    emailHorizontalLayout->insertSpacerItem(1, betweenEmail);
    betweenPassword = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    passwordHorizontalLayout->insertSpacerItem(1, betweenPassword);

    beforePassword = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    verticalLayout->insertSpacerItem(1, beforePassword);
    beforeButton = new QSpacerItem(20, 120, QSizePolicy::Expanding, QSizePolicy::Fixed);
    verticalLayout->insertSpacerItem(3, beforeButton);
    beforeRegLabel = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    verticalLayout->insertSpacerItem(5, beforeRegLabel);
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete centralWidget;

    if (mentor != nullptr)
        delete mentor;
    if(student != nullptr)
        delete student;
}

void AuthorizationWindow::onAuthorizationButtonClicked()
{
    QString login = emailLine->text();
    QString password = passwordLine->text();

    std::string values[] = {login.toStdString(), password.toStdString()};

    AuthorizationMenu menu;
    UserInfo guest;

    if (menu.validation(values, std::size(values)))
    {
        menu.login(guest, values);
    }
    else
    {
        QMessageBox::information(this, "Информация", "Проверьте введенные данные. Возможно вы не зарегистрированы в системе.");
    }

    if(guest.getRole() == "MENTOR")
    {
        mentor = new Mentor(guest);
        replaceWithMentorWindow();
    }
    else if(guest.getRole() == "STUDENT")
    {
        student = new Student(guest);
        replaceWithStudentWindow();
    }
}

void AuthorizationWindow::updateAuthorizationButtonState()
{
    if(!emailLine->text().isEmpty() && !passwordLine->text().isEmpty())
        authorizationButton->setEnabled(true);
    else
        authorizationButton->setEnabled(false);
}

void AuthorizationWindow::replaceWithMentorWindow()
{
    MentorWindow *mentorWindow = new MentorWindow(mentor);

    this->close();
    mentorWindow->show();
}

void AuthorizationWindow::replaceWithRegistrationWindow()
{
    RegistrationWindow *registrationWindow = new RegistrationWindow();

    registrationWindow->show();
    this->close();
}

void AuthorizationWindow::replaceWithStudentWindow()
{
    StudentWindow *studentWindow = new StudentWindow(student);

    this->close();
    studentWindow->show();
}
