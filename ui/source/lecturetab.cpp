#include "lecturetab.h"
#include "database.h"

LectureTab::LectureTab(const Lecture& lecture, QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout(this);

    lectureText = new QTextBrowser();
    lectureText->setText(QString::fromStdString(getText(lecture)));
    mainLayout->addWidget(lectureText);

    returnToCoursesList = new QPushButton("Вернуться к списку лекций");
    mainLayout->addWidget(returnToCoursesList);
    connect(returnToCoursesList, &QPushButton::clicked, this, [this](){delete this;});
}

std::string LectureTab::getText(const Lecture& lecture)
{
    Database database;

    std::string fieldNames[1] = {"text"};

    const int nrows = database.getNrows(std::format("lectures WHERE id = {}", lecture.getId()), fieldNames, std::size(fieldNames));
    const int nfields = database.getNfields(std::format("lectures WHERE id = {}", lecture.getId()), fieldNames, std::size(fieldNames));

    std::string* temp = new std::string[nrows * nfields];

    temp = database.selectFromPostgres(std::format("lectures WHERE id = {}", lecture.getId()), fieldNames, temp, std::size(fieldNames));

    return temp[0];
}
