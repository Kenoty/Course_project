#include <QFileDialog>
#include <QMessageBox>

#include "lecturecreationwindow.h"
#include "database.h"
#include "mentor.h"

LectureCreationWindow::LectureCreationWindow(Course &course, QWidget *parent)
    : QMainWindow{parent}
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setMinimumSize(400, 300);

    centralLayout = new QVBoxLayout(centralWidget);

    nameLayout = new QHBoxLayout();
    centralLayout->addLayout(nameLayout);

    nameLabel = new QLabel("Название лекции");
    nameLayout->addWidget(nameLabel);

    nameLine = new QLineEdit();
    nameLayout->addWidget(nameLine);

    lectureTextEdit = new QTextEdit();
    lectureTextEdit->setReadOnly(true);
    centralLayout->addWidget(lectureTextEdit);

    selectFileButton = new QPushButton("Выбрать файл");
    centralLayout->addWidget(selectFileButton);

    connect(selectFileButton, &QPushButton::clicked, this, &LectureCreationWindow::selectFile);

    createLectureButton = new QPushButton("Создать");
    centralLayout->addWidget(createLectureButton);
    createLectureButton->setEnabled(false);

    connect(nameLine, &QLineEdit::textChanged, this, [this](const QString& text) {
        createLectureButton->setEnabled(!text.isEmpty());
    });
    connect(createLectureButton, &QPushButton::clicked, this, [this, &course](){createLecture(course);});

    returnButton = new QPushButton("Вернуться");
    returnButton->setStyleSheet("");
    centralLayout->addWidget(returnButton);

    connect(returnButton, &QPushButton::clicked, this, &LectureCreationWindow::goBack);

}

void LectureCreationWindow::selectFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        loadLectureFromFile(fileName);
    }
}

void LectureCreationWindow::goBack()
{
    this->close();
}

void LectureCreationWindow::loadLectureFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        lectureTextEdit->setPlainText(in.readAll());
        file.close();
    } else {
        lectureTextEdit->setPlainText("Не удалось открыть файл!");
    }
}

void LectureCreationWindow::createLecture(Course &course)
{
    Database database;
    const std::string fieldNames = {"lecture_name, text, course_id"};
    std::string values[3] = {nameLine->text().toStdString(), lectureTextEdit->toPlainText().toStdString(), std::to_string(course.getId())};

    const std::string temp = "'" + values[0] + "', '" + values[1] + "', " + values[2];

    database.insertData("lectures", fieldNames, temp);

    course.getLecturesList().clear();

    Mentor account;
    account.getLecturesInfo(course);

    QMessageBox::information(this, "Информация", "Лекция успешно создана");
    goBack();
    emit createButtonClicked();
}
