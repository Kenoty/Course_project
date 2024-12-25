#include "mylineedit.h"



MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{
    shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(3, 3);
    shadowEffect->setBlurRadius(0);
    shadowEffect->setColor(QColor(57, 255, 203));
    setGraphicsEffect(shadowEffect);

    blurAnimation = new QPropertyAnimation(shadowEffect, "blurRadius");
    blurAnimation->setDuration(200);

    offsetAnimation = new QPropertyAnimation(shadowEffect, "offset");
    offsetAnimation->setDuration(200);
}

void MyLineEdit::focusInEvent(QFocusEvent *event)
{
    shadowEffect->setColor(QColor(138, 33, 182));

    blurAnimation->setStartValue(0);
    blurAnimation->setEndValue(15);
    blurAnimation->start();

    offsetAnimation->setStartValue(QPointF(3, 3));
    offsetAnimation->setEndValue(QPointF(-3, -3));
    offsetAnimation->start();

    QLineEdit::focusInEvent(event);
}

void MyLineEdit::focusOutEvent(QFocusEvent *event)
{
    blurAnimation->setStartValue(15);
    blurAnimation->setEndValue(0);
    blurAnimation->start();

    offsetAnimation->setStartValue(QPointF(-3, -3));
    offsetAnimation->setEndValue(QPointF(3, 3));
    offsetAnimation->start();

    shadowEffect->setColor(QColor(57, 255, 203));
    QLineEdit::focusOutEvent(event);
}
