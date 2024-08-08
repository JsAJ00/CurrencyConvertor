#include "mystylesheet.h"

QString myStyleSheet::getButtonPlainStyle()
{
    return "QPushButton{"
           "    background-color: #404040;"
           "    font-family: 'Roboto Mono';"
           "    font-size: 30px;"
           "}"
           ""
           "QPushButton::hover{"
           "    background-color: #333333;"
           "}";
}

QString myStyleSheet::getButtonDigitStyle()
{
    return "QPushButton{"
           "    background-color: #555555;"
           "    font-family: 'Roboto Mono';"
           "    font-size: 30px;"
           "}"
           ""
           "QPushButton::hover{"
           "    background-color: #505050;"
           "}";
}

QString myStyleSheet::getButtonOperationStyle()
{
    return "QPushButton{"
           "    background-color: #DD8800;"
           "    font-family: 'Roboto Mono';"
           "    font-size: 30px;"
           "}"
           ""
           "QPushButton::hover{"
           "    background-color: #CC7700;"
           "}";
}

QString myStyleSheet::getQLabelRealCurrencyStyle()
{
    return "QLabel{"
           "    color: rgb(74, 197, 172);"
           "    font-family: 'Roboto Mono';"
           "    font-size: 15px;"
           "}";
}

QString myStyleSheet::getEditStyle()
{
    return "border: none;"
           "font-size: 35px;"
           "margin-right: 1px;";
}
