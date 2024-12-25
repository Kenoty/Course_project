#ifndef COURSESEARCHTAB_H
#define COURSESEARCHTAB_H

#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QVBoxLayout>
#include <QCompleter>
#include <QPushButton>
#include <QScrollArea>

#include "student.h"

class CourseSearchTab : public QWidget
{
    Q_OBJECT
public:
    CourseSearchTab(Student *account, QWidget *parent = nullptr);
    QStringList convertToQStringList(std::vector<std::string> names, int size);
    std::vector<std::string> getNames(Student *account);

private:
    void setupCompleter();

private slots:
    void onSearchTextChanged(Student *account, const QString &text);
    void onCompleterActivated(const QString &completion);
    void onSearchButtonClicked(const QString &text);

private:
    QLineEdit *searchLineEdit;
    QTableView *tableView;
    QVBoxLayout *centralLayout, *scrollLayout;
    QHBoxLayout *searchLayout;
    QCompleter *completer;
    QPushButton *searchButton;
    QScrollArea *mainArea;
    QWidget *scrollContent;
};

#endif
