#ifndef COURSEEDITWINDOW_H
#define COURSEEDITWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <course.h>

class CourseEditWindow : public QMainWindow
{
    Q_OBJECT
public:
    CourseEditWindow(Course &course, QWidget *parent = nullptr);

signals:
    void updateCard();

private slots:
    void updateCourseInfo(Course &course);
    void goBack();

private:
    QWidget *centralWidget;
    QPushButton *saveButton;
    QGroupBox *editBox;
    QLabel **arrayLabel;
    QLineEdit **arrayLine;
    QVBoxLayout *editBoxLayout, *centralLayout;
    QHBoxLayout **linesHorizontalLayout;
    QPushButton *returnButton;
};

#endif

