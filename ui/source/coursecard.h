#ifndef COURSECARD_H
#define COURSECARD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>

#include "clickablelabel.h"
#include "course.h"
#include "infocard.h"
#include "lectureslisttab.h"

class CourseCard : public InfoCard
{
    Q_OBJECT
public:
    CourseCard(Course& course, QWidget *parent = nullptr);

signals:
    void courseClicked(LecturesListTab *tab);
    void lectureClicked(LectureTab *tab);

private slots:
    void onCourseClicked(LecturesListTab *tab);
    void onLectureClicked(LectureTab *tab);
    void onDeleteButtonClicked(int id);
    void updateCourseInfo(Course& course);
    void updateLectures(Course &course);

private:
    ClickableLabel *courseNameLabel;
    QLabel *coursePriceLabel, *ratingLabel;
    QHBoxLayout *cardLayout;
    QHBoxLayout **stringLayouts;
    LecturesListTab *lecturesListTab;
    QPushButton *editButton, *deleteButton;
};

#endif
