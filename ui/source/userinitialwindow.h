#ifndef USERINITIALWINDOW_H
#define USERINITIALWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>

class UserInitialWindow : public QMainWindow
{
    Q_OBJECT
public:
    UserInitialWindow(QWidget *parent = nullptr);

protected:
    QWidget *centralWidget, *startTab;
    QTabWidget *mainTabWidget;
    QHBoxLayout *centralLayout;
    QVBoxLayout *buttonsLayout;
};

#endif
