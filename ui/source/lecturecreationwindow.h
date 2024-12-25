#ifndef LECTURECREATIONWINDOW_H
#define LECTURECREATIONWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>

#include "course.h"

class LectureCreationWindow : public QMainWindow
{
    Q_OBJECT
public:
    LectureCreationWindow(Course &course, QWidget *parent = nullptr);

signals:
    void createButtonClicked();

private slots:
    void selectFile();
    void goBack();
    void loadLectureFromFile(const QString& fileName);
    void createLecture(Course &course);

private:
    QWidget *centralWidget;
    QPushButton *selectFileButton, *createLectureButton;
    QLabel *nameLabel;
    QLineEdit *nameLine;
    QVBoxLayout *centralLayout;
    QHBoxLayout *nameLayout;
    QPushButton *returnButton;
    QTextEdit *lectureTextEdit;
};

#endif
