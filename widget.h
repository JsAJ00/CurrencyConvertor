#ifndef WIDGET_H
#define WIDGET_H

#include "topareaclass.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    virtual ~Widget();

    void writeSettings();
    void readSettings();
private slots:
    void slotButtonClicked();
    void handleNetworkData(QNetworkReply* reply);
private:
    QNetworkAccessManager* manager;

    topAreaClass* top1;
    topAreaClass* top2;
    QWidget* downArea;
    QWidget* splitter;

    void addFonts();
    void createGrid();
    void createSplitter();
    void setButtonStyle();
    void convert();

    QLabel* currencyRate;
    QPushButton *createButton(QString digit);
    QGridLayout* gridForNum;



};

#endif // WIDGET_H
