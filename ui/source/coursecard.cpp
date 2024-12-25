#include <QMessageBox>

#include "coursecard.h"
#include "database.h"
#include "courseeditWindow.h"

CourseCard::CourseCard(Course &course, QWidget *parent)
    : InfoCard{parent}
{
    cardLayout = new QHBoxLayout(this);
    courseNameLabel = new ClickableLabel(QString::fromStdString(course.getName()));
    cardLayout->addWidget(courseNameLabel);
    courseNameLabel->setAlignment(Qt::AlignLeft);

    connect(courseNameLabel, &ClickableLabel::clicked, this, [this, &course]()
    {
        lecturesListTab = new LecturesListTab(course);
        onCourseClicked(lecturesListTab);
        connect(lecturesListTab, &LecturesListTab::lectureClicked, this, [this](LectureTab* tab) {onLectureClicked(tab);});
        connect(lecturesListTab, &LecturesListTab::createButtonClicked, this, [this, &course](){updateLectures(course);});
        connect(lecturesListTab, &LecturesListTab::deleteLecture, this, [this, &course](){updateLectures(course);});
    });

    coursePriceLabel = new QLabel(QString::number(course.getPrice()));
    cardLayout->addWidget(coursePriceLabel);
    coursePriceLabel->setAlignment(Qt::AlignRight);

    editButton = new QPushButton("Редкатировать");
    cardLayout->addWidget(editButton);
    connect(editButton, &QPushButton::clicked, this,[this, &course]()
            {
                CourseEditWindow *window = new CourseEditWindow(course, this);
                window->show();
                connect(window, &CourseEditWindow::updateCard, this, [this, &course](){updateCourseInfo(course);});
            });

    deleteButton = new QPushButton("Удалить");
    cardLayout->addWidget(deleteButton);
    connect(deleteButton, &QPushButton::clicked, this, [this, &course](){onDeleteButtonClicked(course.getId());});
}

void CourseCard::updateCourseInfo(Course &course)
{
    courseNameLabel->setText(QString::fromStdString(course.getName()));
    coursePriceLabel->setText(QString::number(course.getPrice()));
}

void CourseCard::onCourseClicked(LecturesListTab *tab)
{
    emit courseClicked(tab);
}

void CourseCard::onLectureClicked(LectureTab *tab)
{
    emit lectureClicked(tab);
}

void CourseCard::onDeleteButtonClicked(int id)
{
    Database database;
    database.deleteData("courses", std::to_string(id));

    QMessageBox::information(this, "Информация", "Курс был успешно удален.");
    delete this;
}

void CourseCard::updateLectures(Course& course)
{
    delete lecturesListTab;
    lecturesListTab = new LecturesListTab(course);
    onCourseClicked(lecturesListTab);
    connect(lecturesListTab, &LecturesListTab::lectureClicked, this, [this](LectureTab* tab) {onLectureClicked(tab);});
    connect(lecturesListTab, &LecturesListTab::createButtonClicked, this, [this, &course](){updateLectures(course);});
    connect(lecturesListTab, &LecturesListTab::deleteLecture, this, [this, &course](){updateLectures(course);});
}
