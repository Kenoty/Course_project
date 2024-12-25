#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QString>

class StyleHelper
{
public:
    StyleHelper(){};
    virtual QString getBoxStyle();
    virtual QString getLinesStyle();
    virtual QString getButtonsStyle();
    virtual QString getLabelsStyle();
};

#endif
