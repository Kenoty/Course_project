#ifndef INFOCARD_H
#define INFOCARD_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>

class InfoCard : public QGroupBox
{
    Q_OBJECT
public:
    InfoCard(QWidget *parent = nullptr);

signals:
    void labelClicked();

public slots:
    void onLabelClicked();
};

#endif
