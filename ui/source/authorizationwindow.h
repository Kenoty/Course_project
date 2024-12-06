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
#include "clickablelabel.h"
#include "mylineedit.h"
#include "animatedbutton.h"

class AuthorizationWindow : public QMainWindow
{
    Q_OBJECT

public:
    AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();

protected:
    //void paintEvent(QPaintEvent *event);

signals:

private slots:
    void on_authorization_button_clicked();
    void update_authorization_button_state();
    void replace_with_mentor_window();
    void replace_with_registration_window();
private:
    QWidget *central_widget;
    QGroupBox *authorization_box;
    AnimatedButton *authorization_button;
    QLabel *email_label, *password_label;
    ClickableLabel *registration_label;
    MyLineEdit *email_line, *password_line;
    QVBoxLayout *vertical_layout, *window_layout, *registerLabelLayout;
    QHBoxLayout *email_horizontal_layout, *password_horizontal_layout;
    Mentor *mentor;
    QSpacerItem *betweenEmail, *betweenPassword, *beforeButton, *beforeRegLabel, *beforePassword;
};

#endif // AUTHORIZATIONWINDOW_H
