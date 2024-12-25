#include <QScrollArea>
#include <QTableView>
#include <QStandardItemModel>
#include <QDialog>
#include <QHeaderView>

#include "coursesearchcard.h"

CourseSearchCard::CourseSearchCard(std::string &name, std::string &id, QWidget *parent): InfoCard{parent}, id(id)
{
    cardLayout = new QHBoxLayout(this);

    courseNameLabel = new ClickableLabel(QString::fromStdString(name));
    cardLayout->addWidget(courseNameLabel);
    courseNameLabel->setAlignment(Qt::AlignLeft);

    connect(courseNameLabel, &ClickableLabel::clicked, this, &CourseSearchCard::showLectures);

    buyButton = new QPushButton("Купить");
    cardLayout->addWidget(buyButton);
}

void CourseSearchCard::showLectures()
{ 
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Lectures");

    QTableView *tableView = new QTableView();
    QStandardItemModel *model = new QStandardItemModel();

    int rows = 3;
    int columns = 1;
    model->setRowCount(rows);
    model->setColumnCount(columns);

    std::vector<std::string> data = {
        "Item 1",
        "Item 2",
        "Item 3"
    };

    for (int row = 0; row < rows; row++) {
        QStandardItem *item = new QStandardItem(QString::fromStdString(data[row]));
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        model->setItem(row, 0, item);
    }

    tableView->setModel(model);

    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();

    tableView->horizontalHeader()->setVisible(false);
    tableView->verticalHeader()->setVisible(false);
    tableView->horizontalHeader()->setStretchLastSection(true);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(tableView);
    dialog->setLayout(layout);

    dialog->resize(200, 300);

    dialog->exec();
}
