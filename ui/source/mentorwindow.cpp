#include <QStyleOption>
#include <QMessageBox>

#include "mentorwindow.h"
#include "filterswindow.h"

MentorWindow::MentorWindow(Mentor* account, QWidget *parent)
    : UserInitialWindow{parent}
{
    // centralWidget = new QWidget(this);
    // setCentralWidget(centralWidget);

    // centralWidget->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(138, 33, 182, 255), stop:1 rgba(47, 164, 188, 255))");
    // centralWidget->setMinimumSize(800, 600);

    // centralLayout = new QHBoxLayout(centralWidget);

    // mainTabWidget = new QTabWidget();
    // mainTabWidget->setStyleSheet("background-color: #212121");

    // centralLayout->addWidget(mainTabWidget);

    // startTab = new QWidget();
    // mainTabWidget->addTab(startTab, "Начало");

    createListOfCoursesTab(account);

    downloadReportButton = new QPushButton("Загрузить отчет", startTab);
    connect(downloadReportButton, &QPushButton::clicked, this, [this, account](){FiltersWindow *window = new FiltersWindow(account, this); window->show();});
}

void MentorWindow::openCourseCreationTab(Mentor* account)
{
    courseCreationTab = new CourseCreationTab();
    mainTabWidget->addTab(courseCreationTab, "");

    connect(courseCreationTab->getCreateButtonPtr(), &QPushButton::clicked, this, [this, account](){MentorWindow::createCourse(account, courseCreationTab);});
    connect(courseCreationTab->getCreateButtonPtr(), &QPushButton::clicked, this, &MentorWindow::closeCourseCreationTab);
}

void MentorWindow::createCourse(Mentor *account, CourseCreationTab *tab)
{
    std::string *values = new std::string[3]{courseCreationTab->getNameLinePtr()->text().toStdString(), courseCreationTab->getPriceLinePtr()->text().toStdString(), std::to_string(account->getId())};

    account->createCourse(values);
    account->getCourseInfo();

    delete listOfCoursesTab;
    createListOfCoursesTab(account);
}

void MentorWindow::closeCourseCreationTab()
{
    QMessageBox::information(courseCreationTab, "Информация", "Курс был успешно создан.");

    delete courseCreationTab;
}

void MentorWindow::createListOfCoursesTab(Mentor *account)
{
    listOfCoursesTab = new MentorsCoursesTab(account);
    mainTabWidget->addTab(listOfCoursesTab, "Мои курсы");
    connect(listOfCoursesTab, &MentorsCoursesTab::courseClicked, this, [this](LecturesListTab *tab){mainTabWidget->addTab(tab, "");mainTabWidget->setCurrentWidget(tab);});
    connect(listOfCoursesTab, &MentorsCoursesTab::lectureClicked, this, [this](LectureTab *tab){mainTabWidget->addTab(tab, "");mainTabWidget->setCurrentWidget(tab);});
    connect(listOfCoursesTab->getCreateCourseButtonPtr(), &QPushButton::clicked, this, [this, account](){MentorWindow::openCourseCreationTab(account);});
    connect(listOfCoursesTab->getCreateCourseButtonPtr(), &QPushButton::clicked, this, [this](){mainTabWidget->setCurrentWidget(courseCreationTab);});
}
