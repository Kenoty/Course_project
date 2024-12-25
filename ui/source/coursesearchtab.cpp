#include <QStringListModel>

#include "coursesearchtab.h"
#include "coursesearchcard.h"

CourseSearchTab::CourseSearchTab(Student *account, QWidget *parent)
    : QWidget{parent}
{
    centralLayout = new QVBoxLayout(this);
    searchLayout = new QHBoxLayout();
    centralLayout->addLayout(searchLayout);

    searchLineEdit = new QLineEdit();
    searchLayout->addWidget(searchLineEdit);

    searchButton = new QPushButton("Найти");
    searchLayout->addWidget(searchButton);
    connect(searchButton, &QPushButton::clicked, this, [this](){onSearchButtonClicked(searchLineEdit->text());});
    //setupCompleter();
    //connect(completer, SIGNAL(activated(const QString &)), this, SLOT(onCompleterActivated(const QString &)));

    mainArea = new QScrollArea();
    centralLayout->addWidget(mainArea);
    mainArea->setWidgetResizable(true);

    scrollContent = new QWidget();
    mainArea->setWidget(scrollContent);

    scrollLayout = new QVBoxLayout();
    scrollContent->setLayout(scrollLayout);

    // tableView = new QTableView();
    // centralLayout->addWidget(tableView);

   // connect(searchLineEdit, &QLineEdit::textChanged, this, [this, account](){onSearchTextChanged(account, searchLineEdit->text());});
}

QStringList CourseSearchTab::convertToQStringList(std::vector<std::string> names, int size)
{
    QStringList result;

    for (int i = 0; i < size; i += 2) {
        result.append(QString::fromStdString(names[i]));
    }

    return result;
}

void CourseSearchTab::CourseSearchTab::onSearchTextChanged(Student *account, const QString &text)
{
    if (text.isEmpty()) {
        completer->setModel(new QStringListModel(QStringList(), completer));
        return;
    }

    QStringList filteredCourseNames;
    QStringList courseNames = convertToQStringList(getNames(account), 3);
    for (const QString &name : courseNames) {
        if (name.contains(text, Qt::CaseInsensitive)) {
            filteredCourseNames << name;
        }
    }

    completer->setModel(new QStringListModel(filteredCourseNames, completer));

    if (!filteredCourseNames.isEmpty()) {
        QStringListModel *model = new QStringListModel(filteredCourseNames, completer);
        completer->setModel(model);
        completer->complete(searchLineEdit->rect());
    } else {
        completer->popup()->hide();
    }
}

void CourseSearchTab::CourseSearchTab::onCompleterActivated(const QString &completion)
{

    //searchLineEdit->setText(completion);
    searchLineEdit->setFocus();

    // QModelIndex index = completer->completionModel()->index(0, 0);
    // completer->setCurrentIndex(index);
}

void CourseSearchTab::onSearchButtonClicked(const QString &text)
{
    Student temp;
    std::vector<std::string> vector;

    vector = temp.findCourses(text.toStdString());

    CourseSearchCard *card;
    for(int i = 0; i < vector.size(); i+= 2)
    {
        card = new CourseSearchCard(vector[i], vector[i + 1]);
        scrollLayout->addWidget(card);
    }
    scrollLayout->addStretch();
}

void CourseSearchTab::setupCompleter()
{
    completer = new QCompleter(this);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    searchLineEdit->setCompleter(completer);
}

std::vector<std::string> CourseSearchTab::getNames(Student *account)
{
    std::vector<std::string> temp;

    temp = account->findCourses(searchLineEdit->text().toStdString());

    return temp;
}
