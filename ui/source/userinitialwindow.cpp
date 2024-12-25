#include "userinitialwindow.h"

UserInitialWindow::UserInitialWindow(QWidget *parent)
    : QMainWindow{parent}
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    centralWidget->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(138, 33, 182, 255), stop:1 rgba(47, 164, 188, 255))");
    centralWidget->setMinimumSize(800, 600);

    centralLayout = new QHBoxLayout(centralWidget);

    mainTabWidget = new QTabWidget();
    mainTabWidget->setStyleSheet("background-color: #212121");

    centralLayout->addWidget(mainTabWidget);

    startTab = new QWidget();
    mainTabWidget->addTab(startTab, "Начало");
}
