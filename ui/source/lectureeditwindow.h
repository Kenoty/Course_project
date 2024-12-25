#ifndef LECTUREEDITWINDOW_H
#define LECTUREEDITWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>

#include "lecture.h"

class LectureEditWindow : public QMainWindow
{
    Q_OBJECT
public:
    LectureEditWindow(Lecture &lecture, QWidget *parent = nullptr);

signals:
    void editButtonClicked();

private slots:
    void selectFile();
    void goBack();
    void loadLectureFromFile(const QString& fileName);
    void saveChanges(Lecture &lecture);

private:
    QWidget *centralWidget;
    QPushButton *selectFileButton, *saveChangesButton;
    QLabel *nameLabel;
    QLineEdit *nameLine;
    QVBoxLayout *centralLayout;
    QHBoxLayout *nameLayout;
    QPushButton *returnButton;
    QTextEdit *lectureTextEdit;
};

#endif
