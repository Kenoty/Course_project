#include "infocard.h"

InfoCard::InfoCard(QWidget *parent)
    : QGroupBox{parent}
{
    this->setFixedHeight(50);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setStyleSheet("InfoCard { border: 2px solid white; border-radius: 5px; }");
}

void InfoCard::onLabelClicked()
{
    emit labelClicked();
}
