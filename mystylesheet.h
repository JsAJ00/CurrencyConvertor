#ifndef MYSTYLESHEET_H
#define MYSTYLESHEET_H

#include <QString>

class myStyleSheet
{
public:
    static QString getButtonPlainStyle();
    static QString getButtonDigitStyle();
    static QString getButtonOperationStyle();
    static QString getQLabelRealCurrencyStyle();
    static QString getEditStyle();
};

#endif // MYSTYLESHEET_H
