#include "courseeditwindow.h"
#include "database.h"
#include <QMessageBox>

CourseEditWindow::CourseEditWindow(Course &course, QWidget *parent)
    : QMainWindow{parent}
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setMinimumSize(400, 300);

    centralLayout = new QVBoxLayout(centralWidget);
    editBox = new QGroupBox();
    //editBox->setFixedSize(180, 220);

    centralLayout->addWidget(editBox);
    centralLayout->setAlignment(editBox, Qt::AlignCenter);

    editBoxLayout = new QVBoxLayout(editBox);

    linesHorizontalLayout = new QHBoxLayout*[2];
    for(int i = 0; i < 2; i++)
        linesHorizontalLayout[i] = new QHBoxLayout();

    arrayLabel = new QLabel*[2];
    for(int i = 0; i < 2; i++)
    {
        arrayLabel[i] = new QLabel();
    }

    arrayLabel[0]->setText("Название курса");
    arrayLabel[1]->setText("Цена");

    arrayLine = new QLineEdit*[2];
    for(int i = 0; i < 2; i++)
    {
        arrayLine[i] = new QLineEdit();
    }

    arrayLine[0]->setText(QString::fromStdString(course.getName()));
    arrayLine[1]->setText(QString::number(course.getPrice()));

    for(int i = 0; i < 2; i++)
    {
        linesHorizontalLayout[i]->addWidget(arrayLabel[i]);
        linesHorizontalLayout[i]->addWidget(arrayLine[i]);
    }

    for(int i = 0; i < 2; i++)
        editBoxLayout->addLayout(linesHorizontalLayout[i]);

    saveButton = new QPushButton("Сохранить");
    centralLayout->addWidget(saveButton);
    connect(saveButton, &QPushButton::clicked, this, [this, &course](){updateCourseInfo(course);});

    returnButton = new QPushButton("Вернуться");
    centralLayout->addWidget(returnButton);
    connect(returnButton, &QPushButton::clicked, this, &CourseEditWindow::goBack);
}

void CourseEditWindow::updateCourseInfo(Course &course)
{
    Database database;
    const std::string fieldNames[] = {"name", "price"};
    course.setName(arrayLine[0]->text().toStdString());
    course.setPrice(arrayLine[1]->text().toFloat());

    database.updateField("courses", fieldNames[0], "'" + course.getName() + "'", std::to_string(course.getId()));
    database.updateField("courses", fieldNames[1], std::to_string(course.getPrice() * 100), std::to_string(course.getId()));

    QMessageBox::information(this, "Информация", "Данные успешно сохранены.");

    emit updateCard();

    goBack();
}

void CourseEditWindow::goBack()
{
    this->close();
}
