#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QComboBox>

#include "animatedbutton.h"
#include "authorizationwindow.h"

class RegistrationWindow : public QMainWindow
{
    Q_OBJECT
public:
    RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

signals:

private slots:
    void onRegistrationButtonClicked();
    void updateRegistrationButtonState();
    void goBackToAuthorizationWindow();

private:
    QWidget *centralWidget;
    QGroupBox *registrationBox;
    AnimatedButton *registrationButton;
    QLabel **arrayLabel;
    QLineEdit **arrayLine;
    QVBoxLayout *registrationBoxLayout, *centralLayout;
    QHBoxLayout **linesHorizontalLayout;
    QComboBox *roleField;
    QPushButton *returnButton;

    AuthorizationWindow *parentWindow;
};

#endif
