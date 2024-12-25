#include "coursecreationtab.h"

CourseCreationTab::CourseCreationTab(QWidget *parent): QWidget(parent)
{
    courseNameLabel = new QLabel("Название курса");
    coursePriceLabel = new QLabel("Цена");
    courseNameLine = new QLineEdit();
    coursePriceLine = new QLineEdit();
    mainLayout = new QVBoxLayout(this);
    nameLayout = new QHBoxLayout();
    priceLayout = new QHBoxLayout();

    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(priceLayout);

    nameLayout->addWidget(courseNameLabel);
    nameLayout->addWidget(courseNameLine);

    priceLayout->addWidget(coursePriceLabel);
    priceLayout->addWidget(coursePriceLine);

    createButton = new QPushButton("Создать");
    mainLayout->addWidget(createButton);

    returnButton = new QPushButton("Вернуться к курсам");
    mainLayout->addWidget(returnButton);

    connect(returnButton, &QPushButton::clicked, this, [this](){delete this;});
}

QPushButton *CourseCreationTab::getCreateButtonPtr()
{
    return this->createButton;
}

QLineEdit *CourseCreationTab::getNameLinePtr()
{
    return this->courseNameLine;
}

QLineEdit *CourseCreationTab::getPriceLinePtr()
{
    return this->coursePriceLine;
}
