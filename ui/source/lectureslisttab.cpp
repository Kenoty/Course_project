#include <QLineEdit>

#include "lectureslisttab.h"
#include "lecturecard.h"
#include "lecturecreationwindow.h"
#include "mentor.h"

LecturesListTab::LecturesListTab(Course& course, QWidget *parent): QScrollArea(parent)
{
    this->setStyleSheet("background-color: #212121");
    this->setWidgetResizable(true);

    listOfLecturesContent = new QWidget();
    this->setWidget(listOfLecturesContent);

    listOfLecturesLayout = new QVBoxLayout(listOfLecturesContent);
    listOfLecturesLayout->setSpacing(5);

    LectureCard *temp;
    for (int i = 0; i < course.getLecturesList().getSize(); i++)
    {
        temp = new LectureCard(course.getLecturesList()[i]);
        listOfLecturesLayout->addWidget(temp);
        connect(temp, &LectureCard::labelClicked, this, [this, &course, i]()
                {
                    lectureTab = new LectureTab(course.getLecturesList()[i]);
                    onLectureClicked(lectureTab);
                });
        connect(temp, &LectureCard::deleteLecture, this, [this, &course](){onDeleteClicked(course);});
    }
    listOfLecturesLayout->addStretch();

    createLectureButton = new QPushButton("Добавить лекцию");
    listOfLecturesLayout->addWidget(createLectureButton);
    connect(createLectureButton, &QPushButton::clicked, this, [this, &course]()
        {
            LectureCreationWindow *window = new LectureCreationWindow(course, this);
            window->show();
            connect(window, &LectureCreationWindow::createButtonClicked, this, &LecturesListTab::onCreateButtonCliked);
        });

    returnButton = new QPushButton("Вернуться к курсам");
    listOfLecturesLayout->addWidget(returnButton);
    connect(returnButton, &QPushButton::clicked, this, [this](){delete this;});
}

void LecturesListTab::onLectureClicked(LectureTab *tab)
{
    emit lectureClicked(tab);
}

void LecturesListTab::onCreateButtonCliked()
{
    emit createButtonClicked();
}

void LecturesListTab::onDeleteClicked(Course &course)
{
    course.getLecturesList().clear();

    Mentor account;
    account.getLecturesInfo(course);

    emit deleteLecture();
}
