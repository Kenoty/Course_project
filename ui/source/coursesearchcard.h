#ifndef COURSESEARCHCARD_H
#define COURSESEARCHCARD_H

#include <QPushButton>

#include "infocard.h"
#include "clickablelabel.h"

class CourseSearchCard: public InfoCard
{
public:
    CourseSearchCard(std::string &name, std::string &id, QWidget *parent = nullptr);

private slots:
    void showLectures();

private:
    std::string id;
    ClickableLabel *courseNameLabel;
    QHBoxLayout *cardLayout;
    QPushButton *buyButton;
};

#endif
