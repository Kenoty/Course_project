#ifndef LECTURESLISTTAB_H
#define LECTURESLISTTAB_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

#include "lecturetab.h"
#include "course.h"

class LecturesListTab : public QScrollArea
{
    Q_OBJECT
public:
    LecturesListTab(Course& course, QWidget *parent = nullptr);

signals:
    void lectureClicked(LectureTab *tab);
    void createButtonClicked();
    void deleteLecture();

private slots:
    void onLectureClicked(LectureTab *tab);
    void onCreateButtonCliked();
    void onDeleteClicked(Course &course);

private:
    QWidget *listOfLecturesContent;
    QVBoxLayout *listOfLecturesLayout;
    QPushButton *createLectureButton, *returnButton;
    LectureTab *lectureTab;
};

#endif
