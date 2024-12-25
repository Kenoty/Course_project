#ifndef COURSECREATIONTAB_H
#define COURSECREATIONTAB_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class CourseCreationTab: public QWidget
{
public:
    CourseCreationTab(QWidget *parent = nullptr);
    QPushButton* getCreateButtonPtr();
    QLineEdit * getNameLinePtr();
    QLineEdit * getPriceLinePtr();

private slots:
    void createCourse();

private:
    QLabel *courseNameLabel, *coursePriceLabel;
    QLineEdit *courseNameLine, *coursePriceLine;
    QVBoxLayout *mainLayout;
    QHBoxLayout *nameLayout, *priceLayout;
    QPushButton *createButton, *returnButton;
};

#endif
