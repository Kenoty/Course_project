#ifndef MENTORWINDOW_H
#define MENTORWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QTabWidget>
#include <QPainter>
#include <QScrollArea>

class MentorWindow : public QMainWindow
{
    Q_OBJECT
public:
    MentorWindow(QWidget *parent = nullptr);

protected:

signals:

private:
    QWidget *centralWidget, *startTab, *listOfCoursesContent;
    QTabWidget *mainTabWidget;
    QHBoxLayout *centralLayout;
    QVBoxLayout *listOfCoursesLayout;
    QScrollArea *listOfCoursesTab;
};

#endif // MENTORWINDOW_H
