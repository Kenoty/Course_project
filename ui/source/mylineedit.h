#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QObject>
#include <QLineEdit>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QFocusEvent>


class MyLineEdit : public QLineEdit {
    Q_OBJECT

public:
    MyLineEdit(QWidget *parent = nullptr);

protected:
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

private:
    QGraphicsDropShadowEffect *shadowEffect;
    QPropertyAnimation *blurAnimation;
    QPropertyAnimation *offsetAnimation;
};

#endif // MYLINEEDIT_H
