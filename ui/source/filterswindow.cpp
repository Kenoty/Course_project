#include "filterswindow.h"

FiltersWindow::FiltersWindow(Mentor *account, QWidget *parent)
    : QMainWindow{parent}
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setMinimumSize(400, 300);

    centralLayout = new QVBoxLayout(centralWidget);
    filtersBox = new QGroupBox();
    filtersBox->setFixedSize(160, 180);

    centralLayout->addWidget(filtersBox);
    centralLayout->setAlignment(filtersBox, Qt::AlignCenter);

    filtersBoxLayout = new QVBoxLayout(filtersBox);

    linesHorizontalLayout = new QHBoxLayout*[5];
    for(int i = 0; i < 5; i++)
        linesHorizontalLayout[i] = new QHBoxLayout();

    arrayLabel = new QLabel*[5];
    for(int i = 0; i < 5; i++)
    {
        arrayLabel[i] = new QLabel();
    }

    arrayLabel[0]->setText("Имя");
    arrayLabel[1]->setText("Фамилия");
    arrayLabel[2]->setText("Отчество");
    arrayLabel[3]->setText("Номер");
    arrayLabel[4]->setText("Почта");

    arrayLine = new QLineEdit*[5];
    for(int i = 0; i < 5; i++)
    {
        arrayLine[i] = new QLineEdit();
    }

    for(int i = 0; i < 5; i++)
    {
        linesHorizontalLayout[i]->addWidget(arrayLabel[i]);
        linesHorizontalLayout[i]->addWidget(arrayLine[i]);
    }

    for(int i = 0; i < 5; i++)
        filtersBoxLayout->addLayout(linesHorizontalLayout[i]);

    downloadReportButton = new QPushButton("Загрузить отчет");
    filtersBoxLayout->addWidget(downloadReportButton);

    connect(downloadReportButton, &QPushButton::clicked, this, [this, account](){onDownloadButtonClicked(account);});

    returnButton = new QPushButton("Вернуться");
    returnButton->setStyleSheet("");
    centralLayout->addWidget(returnButton);

    connect(returnButton, &QPushButton::clicked, this, &FiltersWindow::goBack);
}

void FiltersWindow::onDownloadButtonClicked(Mentor* account)
{
    std::string filters[5];
    for(int i = 0; i < 5; i++)
        if(!arrayLine[i]->text().isEmpty())
        {
            std::string str = arrayLine[i]->text().toStdString();
            filters[i] = str;
        }
        else
            filters[i] = "";

    std::string *result = account->getStudents(filters);

}

void FiltersWindow::goBack()
{
    this->close();
}
