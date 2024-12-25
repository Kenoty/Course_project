#include <QMessageBox>

#include "lecturecard.h"
#include "database.h"
#include "lectureeditwindow.h"

LectureCard::LectureCard(Lecture &lecture, QWidget *parent): InfoCard(parent)
{
    cardLayout = new QHBoxLayout(this);
    lectureNameLabel = new ClickableLabel(QString::fromStdString(lecture.getLectureName()));
    cardLayout->addWidget(lectureNameLabel);
    lectureNameLabel->setAlignment(Qt::AlignLeft);
    connect(lectureNameLabel, &ClickableLabel::clicked, this, &InfoCard::onLabelClicked);

    editLectureButton= new QPushButton("Редактировать");
    cardLayout->addWidget(editLectureButton);
    connect(editLectureButton, &QPushButton::clicked, this, [this, &lecture](){editLecture(lecture);});

    deleteButton = new QPushButton("Удалить");
    cardLayout->addWidget(deleteButton);
    connect(deleteButton, &QPushButton::clicked, this, [this, &lecture](){onDeleteButtonClicked(lecture);});
}

void LectureCard::onDeleteButtonClicked(Lecture &lecture)
{
    Database database;
    database.deleteData("lectures", std::to_string(lecture.getId()));

    QMessageBox::information(this, "Информация", "Лекция была успешно удалена.");
    emit deleteLecture();
}

void LectureCard::editLecture(Lecture &lecture)
{
    LectureEditWindow *window = new LectureEditWindow(lecture);
    window->show();
    connect(window, &LectureEditWindow::editButtonClicked, this, [this, &lecture](){lectureNameLabel->setText(QString::fromStdString(lecture.getLectureName()));});
}
