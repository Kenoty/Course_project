#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QCursor>

class ClickableLabel: public QLabel
{
    Q_OBJECT
public:
    ClickableLabel(const QString &text = "", QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

signals:
    void clicked();
};

#endif
