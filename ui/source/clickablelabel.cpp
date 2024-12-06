#include "clickablelabel.h"

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
    setCursor(Qt::PointingHandCursor);
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked();

    QLabel::mousePressEvent(event);
}

void ClickableLabel::enterEvent(QEnterEvent *event) {
    setCursor(Qt::PointingHandCursor);
    QLabel::enterEvent(event);
}

void ClickableLabel::leaveEvent(QEvent *event) {
    setCursor(Qt::ArrowCursor);
    QLabel::leaveEvent(event);
}
