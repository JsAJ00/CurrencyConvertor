#include "topareaclass.h"
#include "mystylesheet.h"

topAreaClass::topAreaClass(QString path, QWidget *parent)
    : QWidget{parent}, m_path(path)
{
    //main widget setting
    setSizePolicy     (QSizePolicy::Expanding, QSizePolicy::Fixed);
    setFixedSize      (WINDOWWIDTH, 70);
    setStyleSheet     ("background: #222222;");
    setContentsMargins(0,0,0,0);

    //initializations
    topArea                 = new QWidget(this);
    leftTopArea             = new QWidget(topArea);
    leftTopVBoxLayout       = new QVBoxLayout(leftTopArea);
    m_ppixLabelCurrency     = new QPixmap(m_path);
    m_pcurrencyLabelPicture = new QLabel;
    m_pnameOfcurrency       = new QComboBox;
    m_pedit                 = new QLineEdit;
    topHBoxLayout           = new QHBoxLayout(this);


    //leftTopArea
    leftTopArea->setFixedSize(70, 70);
    leftTopArea->setStyleSheet("background: #222222;");
    leftTopVBoxLayout->setContentsMargins(5,5,5,5);


    //Flag
    m_pcurrencyLabelPicture->setPixmap(m_ppixLabelCurrency->scaled(60,30, Qt::KeepAspectRatio));
    m_pcurrencyLabelPicture->setAlignment(Qt::AlignCenter);


    //Currencies
    m_pnameOfcurrency->setFixedSize(80, 30);
    QStringList ls;
    ls<<"UAH"<<"USD"<<"EUR"<<"RUB"<<"PLN"<<"JPY"<<"GBP";
    m_pnameOfcurrency->addItems(ls);

    setStartId();


    //edit1 (topRight)
    m_pedit->setMaxLength(12);
    m_pedit->setEnabled(false);
    m_pedit->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_pedit->setStyleSheet(myStyleSheet::getEditStyle());
    m_pedit->setFixedHeight(70);


    //set layouts
    leftTopVBoxLayout->addWidget(m_pcurrencyLabelPicture);
    leftTopVBoxLayout->addWidget(m_pnameOfcurrency);

    topHBoxLayout->setContentsMargins(0,0,0,0);
    topHBoxLayout->addWidget(leftTopArea);
    topHBoxLayout->addWidget(m_pedit);
    topHBoxLayout->setSpacing(0);


    //connectings
    connect(m_pnameOfcurrency, SIGNAL(currentTextChanged(QString)), SLOT(slotCurrentIndexChanged()));
}

//functions
void topAreaClass::changedFlag(QString currency)
{
    QString newPath;
    if(currency == "UAH"){
        newPath = ":/new/prefix1/resourses/img/uah.png";
    }else if (currency == "USD"){
        newPath = ":/new/prefix1/resourses/img/usa.png";
    }else if (currency == "EUR"){
        newPath = ":/new/prefix1/resourses/img/eur.png";
    }else if (currency == "RUB"){
        newPath = ":/new/prefix1/resourses/img/rus.png";
    }else if(currency == "GBP"){
        newPath = ":/new/prefix1/resourses/img/GBP.png";
    }else if(currency == "JPY"){
        newPath = ":/new/prefix1/resourses/img/JPY";
    }else{
        newPath = ":/new/prefix1/resourses/img/PLN";
    }
    m_pcurrencyLabelPicture->setPixmap(QPixmap(newPath).scaled(60,30, Qt::KeepAspectRatio));
}


void topAreaClass::setStartId()
{

    if(m_path == ":/new/prefix1/resourses/img/eur.png"){
        id = 2;
    }else if(m_path == ":/new/prefix1/resourses/img/rus.png"){
        id = 3;
    }else if (m_path == ":/new/prefix1/resourses/img/uah.png"){
        id = 0;
    }else if (m_path == ":/new/prefix1/resourses/img/usa.png"){
        id = 1;
    }else if(m_path == ":/new/prefix1/resourses/img/PLN"){
        id = 4;
    }else if(m_path == ":/new/prefix1/resourses/img/JPY"){
        id = 5;
    }else{
        id = 6;
    }
    m_pnameOfcurrency->setCurrentIndex(id);
}


void topAreaClass::setEdit(const QString &str)
{
    m_pedit->setText(str);
}

void topAreaClass::clear(){
    m_pedit->clear();
}

QString topAreaClass::getM_edit1Text(){
    return m_pedit->text();
}

QString topAreaClass::getCurrency(){
    return m_pnameOfcurrency->currentText();
}


//slots
void topAreaClass::slotCurrentIndexChanged()
{
    changedFlag(m_pnameOfcurrency->currentText());
}

