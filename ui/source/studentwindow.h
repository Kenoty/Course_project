#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QTabWidget>
#include <QScrollArea>

#include "student.h"
#include "userinitialwindow.h"

class StudentWindow : public UserInitialWindow
{
    Q_OBJECT
public:
    StudentWindow(Student *account, QWidget *parent = nullptr);

private:
    //QWidget *courseSearchTab;
};

#endif
