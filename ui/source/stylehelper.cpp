#include "stylehelper.h"

QString StyleHelper::getBoxStyle()
{
    return  R"(
            QGroupBox {
            background-color: #212121;
            border-radius: 20px;
            padding: 20px;
            })";
}

QString StyleHelper::getLinesStyle()
{
    return R"(
            QLineEdit {
                background-color: #212121;
                color: white;
                border: none;
                padding: 10px;
                border-radius: 5px;
            }
        )";
}

QString StyleHelper::getButtonsStyle()
{
    return R"(
            QPushButton {
                width: 100px;
                height: 40px;
                border-radius: 20px;
                background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(138, 33, 182, 255), stop:1 rgba(47, 164, 188, 255));
                border: none;
                font-size: 14px;
                color: white;
            }
                )";
}

QString StyleHelper::getLabelsStyle()
{
    return R"(
            QLabel{
            background-color: #212121;
            color: white;
            }
                )";
}
