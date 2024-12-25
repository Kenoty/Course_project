#ifndef REGSTYLEHELPER_H
#define REGSTYLEHELPER_H

#include <QString>

#include "stylehelper.h"

class RegStyleHelper: public StyleHelper
{
public:
    RegStyleHelper():StyleHelper(){};
    QString getBoxStyle() override;
    QString getLinesStyle() override;
    QString getButtonsStyle() override;
    QString getLabelsStyle() override;
    static QString getComboBoxStyle();
};

#endif
