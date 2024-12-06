#ifndef ANIMATEDBUTTON_H
#define ANIMATEDBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QPropertyAnimation>
#include <QEvent>
#include <QEnterEvent>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsOpacityEffect>
#include <QMouseEvent>

class AnimatedButton : public QPushButton {
    Q_OBJECT

public:
    AnimatedButton(const QString &text, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;

private:
    QPropertyAnimation *enterAnimation;
    QPropertyAnimation *leaveAnimation;
    QGraphicsDropShadowEffect *shadowEffect;
    QPropertyAnimation *shadowOpacityAnimation;
};

#endif // ANIMATEDBUTTON_H
