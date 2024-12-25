#ifndef LECTURETAB_H
#define LECTURETAB_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextBrowser>

#include "lecture.h"

class LectureTab : public QWidget
{
    Q_OBJECT
public:
    LectureTab(const Lecture& lecture, QWidget *parent = nullptr);
    std::string getText(const Lecture& lecture);
signals:

private:
    QTextBrowser *lectureText;
    QVBoxLayout *mainLayout;
    QPushButton *returnToCoursesList;
};

#endif
