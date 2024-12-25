#include <QFileDialog>
#include <QMessageBox>

#include "lectureeditwindow.h"
#include "database.h"

LectureEditWindow::LectureEditWindow(Lecture &lecture, QWidget *parent)
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

    nameLine = new QLineEdit(QString::fromStdString(lecture.getLectureName()));
    nameLayout->addWidget(nameLine);

    lectureTextEdit = new QTextEdit(QString::fromStdString(lecture.getMaterial()));
    centralLayout->addWidget(lectureTextEdit);

    selectFileButton = new QPushButton("Выбрать файл");
    centralLayout->addWidget(selectFileButton);

    connect(selectFileButton, &QPushButton::clicked, this, &LectureEditWindow::selectFile);

    saveChangesButton  = new QPushButton("Сохранить изменения");
    centralLayout->addWidget(saveChangesButton );
    saveChangesButton ->setEnabled(false);

    connect(nameLine, &QLineEdit::textChanged, this, [this](const QString& text) {
        saveChangesButton ->setEnabled(!text.isEmpty());
    });
    connect(saveChangesButton , &QPushButton::clicked, this, [this, &lecture](){saveChanges(lecture);});

    returnButton = new QPushButton("Вернуться");
    returnButton->setStyleSheet("");
    centralLayout->addWidget(returnButton);

    connect(returnButton, &QPushButton::clicked, this, &LectureEditWindow::goBack);

}

void LectureEditWindow::selectFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        loadLectureFromFile(fileName);
    }
}

void LectureEditWindow::goBack()
{
    this->close();
}

void LectureEditWindow::loadLectureFromFile(const QString &fileName)
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

void LectureEditWindow::saveChanges(Lecture &lecture)
{
    Database database;

    lecture.setLectureName(nameLine->text().toStdString());
    lecture.setMaterial(lectureTextEdit->toPlainText().toStdString());

    database.updateField("lectures", "lecture_name", "'" + nameLine->text().toStdString() + "'", std::to_string(lecture.getId()));
    database.updateField("lectures", "text", "'" + lectureTextEdit->toPlainText().toStdString() + "'", std::to_string(lecture.getId()));

    QMessageBox::information(this, "Информация", "Лекция успешно изменена.");
    goBack();
    emit editButtonClicked();
}
