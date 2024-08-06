#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(WINDOWWIDTH, WINDOWWHIGHT);
    setStyleSheet("background: #222222;");
    setWindowTitle("Currency Convertor");
    setWindowIcon(QIcon(QPixmap(":/new/prefix1/resourses/img/MyIcon.ico")));


    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    top1 = new topAreaClass(":/new/prefix1/resourses/img/uah.png");
    top2 = new topAreaClass(":/new/prefix1/resourses/img/uah.png");

    addFonts();
    createSplitter();
    createGrid();
    setButtonStyle();


    //downArea
    downArea = new QWidget(this);
    downArea->setFixedSize(360, 60);

    //realCurrency
    currencyRate = new QLabel(downArea);
    currencyRate->setFixedSize(180,40);
    currencyRate->move(90, 0);
    currencyRate->setStyleSheet(myStyleSheet::getQLabelRealCurrencyStyle());
    currencyRate->setAlignment(Qt::AlignCenter);


    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(top1);
    mainLayout->addWidget(splitter);
    mainLayout->addWidget(top2);
    mainLayout->addLayout(gridForNum);
    mainLayout->addWidget(downArea);


    manager = new QNetworkAccessManager;
    connect(manager, &QNetworkAccessManager::finished, this, &Widget::handleNetworkData);
}

Widget::~Widget() {}


QPushButton *Widget::createButton(QString digit)
{
    QPushButton* btn = new QPushButton(digit);
    btn->setFixedSize(90,90);
    btn->setStyleSheet(myStyleSheet::getButtonPlainStyle());
    connect(btn, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return btn;
}


void Widget::addFonts()
{
    int id = QFontDatabase::addApplicationFont
        (":/new/prefix1/resourses/fonts/RobotoMono-Italic-VariableFont_wght.ttf");
    QString family  = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug()<<family;
}

void Widget::createGrid()
{

    QString map[4][4]{{"C", "0", ".", "="},
                      {"7", "8", "9", "/"},
                      {"4", "5", "6", "-"},
                      {"1", "2", "3", "+"}
    };

    gridForNum = new QGridLayout;
    gridForNum->setSpacing(0);

    for (int i = 0; i<4; ++i){
        for(int j = 0; j<4; ++j){
            gridForNum->addWidget(createButton(map[i][j]), i, j);
        }
    }
}

void Widget::createSplitter()
{
    splitter = new QWidget(this);
    splitter->setFixedSize(WINDOWWIDTH, 1);
    splitter->setStyleSheet("background: gray");
}

void Widget::setButtonStyle()
{
    for (int i = 0; i<4; ++i){
        for(int j = 0; j<4; ++j){
            QPushButton* btn = qobject_cast<QPushButton* >(gridForNum->itemAtPosition(i, j)->widget());
            if (btn->text().contains(QRegularExpression("[0-9]"))){
                btn->setStyleSheet(myStyleSheet::getButtonDigitStyle());
            }else if (btn->text().contains("+") || btn->text().contains("-") || btn->text().contains("=") || btn->text().contains("/")){
                btn->setStyleSheet(myStyleSheet::getButtonOperationStyle());
            }
        }
    }
}


void Widget::slotButtonClicked()
{
    QString str = ((QPushButton*)sender())->text();

    // Check if str contains a digit (0-9)
    if (str.contains(QRegularExpression("[0-9]"))) {
        if (top1) {
            top1->preparing+=str;
            top1->setEdit(top1->preparing);
        }
    }
    // Check if str contains a "."
    else if(str == "."){
        if(!(top1->preparing.contains("."))){
            top1->preparing+=str;
            top1->setEdit(top1->preparing);
        }
    }
    // Check if str contains a "C"
    else if(str=="C"){
        if(!(top1->getM_edit1Text().isEmpty())){
            top1->clear();
            top2->clear();
            top1->preparing.clear();
        }
    }



    else if (str == "="){
        convert();
    }

}

void Widget::convert()
{
    QString amount = top1->getM_edit1Text();
    QString from = top1->getCurrency();
    QString to = top2->getCurrency();
    QString api_key = "Hiw1aYzirsNqpw7BX7QgfpfiYrQ2FWsU";

    QString url = QString(
        "https://api.currencybeacon.com/v1/convert?api_key="+api_key+"&amount="+amount+"&from="+from+"&to="+to);

    manager->get(QNetworkRequest(QUrl(url)));
}


void Widget::handleNetworkData(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QString amount = top1->getM_edit1Text();
        QString from = top1->getCurrency();
        QString to = top2->getCurrency();

        //getting respose from API
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();
        double rates = jsonObj.value("value").toDouble();
        //setting respose from API
        top2->setEdit(QString::number(rates, 'f', 2));
        //setting RealCurrencuy label
        currencyRate->setText("1" + from + " = " + QString::number(rates/amount.toDouble())+to);
    }else{
        top2->setEdit("error");
    }
    reply->deleteLater();
}



