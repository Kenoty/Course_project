#include "regstylehelper.h"

QString RegStyleHelper::getBoxStyle()
{
    return R"(
            QGroupBox {
            background-color: #e8e8e8;
            border-radius: 20px;
            padding: 20px;
            }
            )";
}

QString RegStyleHelper::getLinesStyle()
{
    return R"(
            QLineEdit {
                background-color: #e8e8e8;
                color: black;
                border: 1px solid black;
                padding: 10px;
                border-radius: 5px;
            }
            )";
}

QString RegStyleHelper::getButtonsStyle()
{
    return R"(
            QPushButton {
                width: 100px;
                height: 40px;
                border-radius: 20px;
                background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(254, 182, 146, 255), stop:1 rgba(234, 84, 85, 255));
                border: none;
                font-size: 14px;
                color: white;
            }
            )";
}

QString RegStyleHelper::getLabelsStyle()
{
    return R"(
            QLabel{
            background-color: #e8e8e8;
            color: black;
            }
            )";
}

QString RegStyleHelper::getComboBoxStyle()
{
    return R"(
            QComboBox {
            background-color: #e8e8e8;
            color: black;
            }
            QComboBox QAbstractItemView::item {
            background-color: #e8e8e8;
            }
            )";
}
