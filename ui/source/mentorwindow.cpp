#include <QStyleOption>

#include "mentorwindow.h"

MentorWindow::MentorWindow(QWidget *parent)
    : QMainWindow{parent}
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    centralWidget->setStyleSheet("background-color: lightblue");
    centralWidget->setMinimumSize(800, 600);

    centralLayout = new QHBoxLayout(centralWidget);

    mainTabWidget = new QTabWidget();
    mainTabWidget->setFixedSize(400, 400);
    mainTabWidget->setStyleSheet("background-color: #0ff");

    centralLayout->addWidget(mainTabWidget);

    startTab = new QWidget();
    mainTabWidget->addTab(startTab, "Начало");

    listOfCoursesTab = new QScrollArea();
    listOfCoursesTab->setStyleSheet("background-color: #6ff");

    listOfCoursesContent = new QWidget;
    listOfCoursesLayout = new QVBoxLayout(listOfCoursesContent);

    for (int i = 1; i <= 30; ++i) {
       listOfCoursesLayout->addWidget(new QLabel("Элемент " + QString::number(i)));
    }

    listOfCoursesTab->setWidget(listOfCoursesContent);

    mainTabWidget->addTab(listOfCoursesTab, "Мои курсы");
}
