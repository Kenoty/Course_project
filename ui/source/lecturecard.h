#ifndef LECTURECARD_H
#define LECTURECARD_H

#include <QHBoxLayout>
#include <QPushButton>

#include "infocard.h"
#include "clickablelabel.h"
#include "lecture.h"

class LectureCard: public InfoCard
{
    Q_OBJECT
public:
    LectureCard(Lecture &lecture, QWidget* parent = nullptr);

signals:
    void deleteLecture();

private slots:
    void onDeleteButtonClicked(Lecture &lecture);
    void editLecture(Lecture &lecture);

private:
    ClickableLabel* lectureNameLabel;
    QHBoxLayout *cardLayout;
    QPushButton *editLectureButton, *deleteButton;
};

#endif
