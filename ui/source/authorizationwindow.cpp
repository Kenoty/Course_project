#include "authorizationwindow.h"
#include "authorization_menu.h"
#include "mentorwindow.h"
#include "registrationwindow.h"
#include "stylehelper.h"

#include <QStyleOption>
#include <QPropertyAnimation>
#include <QFocusEvent>

AuthorizationWindow::AuthorizationWindow(QWidget *parent)
    : QMainWindow{parent}
{
    StyleHelper obj;
    StyleHelper *helper = &obj;

    mentor = nullptr;

    central_widget = new QWidget(this);
    setCentralWidget(central_widget);

    central_widget->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(138, 33, 182, 255), stop:1 rgba(47, 164, 188, 255))");
    central_widget->setMinimumSize(800, 600);

    window_layout = new QVBoxLayout(central_widget);

    authorization_box = new QGroupBox();
    authorization_box->setFixedSize(320, 360);
    authorization_box->setStyleSheet(helper->getLinesStyle() + helper->getBoxStyle() + helper->getLabelsStyle());

    window_layout->addWidget(authorization_box);
    window_layout->setAlignment(authorization_box, Qt::AlignCenter);

    authorization_button = new AnimatedButton("Авторизоваться");
    authorization_button->setStyleSheet(helper->getButtonsStyle());
    authorization_button->setEnabled(false);

    connect(authorization_button, &QPushButton::clicked, this, &AuthorizationWindow::on_authorization_button_clicked);
    connect(authorization_button, &QPushButton::clicked, this, &AuthorizationWindow::replace_with_mentor_window);

    vertical_layout = new QVBoxLayout(authorization_box);

    email_horizontal_layout = new QHBoxLayout();
    password_horizontal_layout = new QHBoxLayout();

    vertical_layout->addLayout(email_horizontal_layout);
    vertical_layout->addLayout(password_horizontal_layout);
    vertical_layout->addWidget(authorization_button);

    email_label = new QLabel ("Эл. почта");

    password_label = new QLabel ("Пароль");

    email_line = new MyLineEdit();
    connect(email_line, &QLineEdit::textChanged, this, &AuthorizationWindow::update_authorization_button_state);

    password_line = new MyLineEdit();
    connect(password_line, &QLineEdit::textChanged, this, &AuthorizationWindow::update_authorization_button_state);

    email_horizontal_layout->addWidget(email_label);
    email_horizontal_layout->addWidget(email_line);

    password_horizontal_layout->addWidget(password_label);
    password_horizontal_layout->addWidget(password_line);

    registration_label = new ClickableLabel("Регистрация");
    registration_label->setFixedSize(74, 20);
    connect(registration_label, &ClickableLabel::clicked, this, &AuthorizationWindow::replace_with_registration_window);

    registerLabelLayout = new QVBoxLayout();
    registerLabelLayout->addWidget(registration_label, 0, Qt::AlignHCenter | Qt::AlignBottom);

    vertical_layout->addLayout(registerLabelLayout);

    betweenEmail = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    email_horizontal_layout->insertSpacerItem(1, betweenEmail);
    betweenPassword = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    password_horizontal_layout->insertSpacerItem(1, betweenPassword);

    beforePassword = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    vertical_layout->insertSpacerItem(1, beforePassword);
    beforeButton = new QSpacerItem(20, 120, QSizePolicy::Expanding, QSizePolicy::Fixed);
    vertical_layout->insertSpacerItem(3, beforeButton);
    beforeRegLabel = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    vertical_layout->insertSpacerItem(5, beforeRegLabel);
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete central_widget;

    if (mentor != nullptr)
        delete mentor;
}

void AuthorizationWindow::on_authorization_button_clicked()
{
    QString login = email_line->text();
    QString password = password_line->text();

    std::string values[] = {login.toStdString(), password.toStdString()};

    AuthorizationMenu menu;
    UserInfo guest;

    if (menu.validation(values, std::size(values)))
    {
        menu.login(guest, values);
    }

    if(guest.get_role() == "MENTOR")
    {
        mentor = new Mentor(guest);
    }
}

void AuthorizationWindow::update_authorization_button_state()
{
    if(!email_line->text().isEmpty() && !password_line->text().isEmpty())
        authorization_button->setEnabled(true);
    else
        authorization_button->setEnabled(false);
}

void AuthorizationWindow::replace_with_mentor_window()
{
    if(mentor != nullptr)
    {
        MentorWindow *mentorWindow = new MentorWindow();

        this->hide();
        mentorWindow->show();

        connect(mentorWindow, &QMainWindow::destroyed, this, &QMainWindow::close);
    }
}

void AuthorizationWindow::replace_with_registration_window()
{
    RegistrationWindow *registrationWindow = new RegistrationWindow();

    this->hide();
    registrationWindow->show();

    connect(registrationWindow, &QMainWindow::destroyed, this, &QMainWindow::close);
}
