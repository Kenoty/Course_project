#ifndef FILTERSWINDOW_H
#define FILTERSWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "mentor.h"

class FiltersWindow : public QMainWindow
{
    Q_OBJECT
public:
    FiltersWindow(Mentor *account, QWidget *parent = nullptr);

private slots:
    void onDownloadButtonClicked(Mentor *account);
    void goBack();

private:
    QWidget *centralWidget;
    QPushButton *downloadReportButton;
    QGroupBox *filtersBox;
    QLabel **arrayLabel;
    QLineEdit **arrayLine;
    QVBoxLayout *filtersBoxLayout, *centralLayout;
    QHBoxLayout **linesHorizontalLayout;
    QPushButton *returnButton;
};

#endif
