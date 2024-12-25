#include "studentwindow.h"
#include "coursesearchtab.h"

StudentWindow::StudentWindow(Student *account, QWidget *parent)
    : UserInitialWindow{parent}
{
    CourseSearchTab *courseSearchTab = new CourseSearchTab(account);
    mainTabWidget->addTab(courseSearchTab, "Поиск курсов");

}
