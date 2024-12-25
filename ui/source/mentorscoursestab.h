#ifndef MENTORSCOURSESTAB_H
#define MENTORSCOURSESTAB_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

#include "mentor.h"
#include "lectureslisttab.h"

class MentorsCoursesTab: public QScrollArea
{
    Q_OBJECT
public:
    MentorsCoursesTab(Mentor* account = nullptr, QWidget* parent = nullptr);
    QPushButton* getCreateCourseButtonPtr();

signals:
    void courseClicked(LecturesListTab *tab);
    void lectureClicked(LectureTab *tab);

private slots:
    void onCourseClicked(LecturesListTab *tab);
    void onLectureClicked(LectureTab *tab);

private:
    QWidget *listOfCoursesContent;
    QVBoxLayout *listOfCoursesLayout;
    QPushButton *createCourseButton, *returnButton;
};

#endif
