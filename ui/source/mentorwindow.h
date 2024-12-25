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
#include <QScrollArea>

#include "mentor.h"
#include "coursecreationtab.h"
#include "mentorscoursestab.h"
#include "userinitialwindow.h"

class MentorWindow : public UserInitialWindow
{
public:
    MentorWindow(Mentor* account, QWidget *parent = nullptr);
    void openCourseCreationTab(Mentor* account);
    void createCourse(Mentor* account, CourseCreationTab* tab);
    void closeCourseCreationTab();
    void createListOfCoursesTab(Mentor* account);

private:
    // QWidget *centralWidget, *startTab;
    // QTabWidget *mainTabWidget;
    // QHBoxLayout *centralLayout;
    // QVBoxLayout *buttonsLayout;
    QPushButton *downloadReportButton;
    MentorsCoursesTab *listOfCoursesTab;
    CourseCreationTab *courseCreationTab;
};

#endif
