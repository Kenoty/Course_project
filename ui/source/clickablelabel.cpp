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
    setCursor(Qt::PointingHandCursor); // Меняем курсор при наведении
    QLabel::enterEvent(event); // Вызываем базовый класс
}

void ClickableLabel::leaveEvent(QEvent *event) {
    setCursor(Qt::ArrowCursor); // Возвращаем курсор по умолчанию
    QLabel::leaveEvent(event); // Вызываем базовый класс
}
