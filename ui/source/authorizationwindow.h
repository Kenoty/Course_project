#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QSpacerItem>

#include "mentor.h"
#pragma once

#include "clickablelabel.h"
#include "mylineedit.h"
#include "animatedbutton.h"
#include "student.h"

class AuthorizationWindow : public QMainWindow
{
    Q_OBJECT

public:
    AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();

private slots:
    void onAuthorizationButtonClicked();
    void updateAuthorizationButtonState();
    void replaceWithMentorWindow();
    void replaceWithRegistrationWindow();
    void replaceWithStudentWindow();

private:
    QWidget *centralWidget;
    QGroupBox *authorizationBox;
    AnimatedButton *authorizationButton;
    QLabel *emailLabel, *passwordLabel;
    ClickableLabel *registrationLabel;
    MyLineEdit *emailLine, *passwordLine;
    QVBoxLayout *verticalLayout, *windowLayout, *registerLabelLayout;
    QHBoxLayout *emailHorizontalLayout, *passwordHorizontalLayout;
    Mentor *mentor;
    Student *student;
    QSpacerItem *betweenEmail, *betweenPassword, *beforeButton, *beforeRegLabel, *beforePassword;
};

#endif
