#include "animatedbutton.h"

AnimatedButton::AnimatedButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    enterAnimation = new QPropertyAnimation(this, "pos");
    leaveAnimation = new QPropertyAnimation(this, "pos");

    enterAnimation->setDuration(100);
    leaveAnimation->setDuration(100);

    shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(30);
    shadowEffect->setOffset(0, 15);
    shadowEffect->setColor(QColor(138, 33, 182, 127));
    setGraphicsEffect(shadowEffect);

    shadowOpacityAnimation = new QPropertyAnimation(shadowEffect, "color");
    shadowOpacityAnimation->setDuration(100);
}

void AnimatedButton::mousePressEvent(QMouseEvent *event)
{
    shadowOpacityAnimation->setStartValue(QColor(138, 33, 182, 127));
    shadowOpacityAnimation->setEndValue(QColor(138, 33, 182, 0));
    shadowOpacityAnimation->start();

    enterAnimation->setStartValue(pos());
    enterAnimation->setEndValue(pos() + QPoint(0, 3));
    enterAnimation->start();

    QPushButton::mousePressEvent(event);
}

void AnimatedButton::mouseReleaseEvent(QMouseEvent *event)
{
    shadowOpacityAnimation->setStartValue(QColor(138, 33, 182, 0));
    shadowOpacityAnimation->setEndValue(QColor(138, 33, 182, 127));
    shadowOpacityAnimation->start();

    leaveAnimation->setStartValue(pos());
    leaveAnimation->setEndValue(pos() - QPoint(0, 3));
    leaveAnimation->start();

    QPushButton::mouseReleaseEvent(event);
}
