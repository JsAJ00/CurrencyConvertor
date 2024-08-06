#include "topareaclass.h"

topAreaClass::topAreaClass(QString path, QWidget *parent)
    : QWidget{parent}, m_path(path)
{
    //topArea
    topArea = new QWidget(this);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setFixedSize(WINDOWWIDTH, 70);
    setStyleSheet("background: #222222;");
    setContentsMargins(0,0,0,0);


    //leftTopArea
    leftTopArea = new QWidget(topArea);
    leftTopArea->setFixedSize(70, 70);
    leftTopArea->setStyleSheet("background: #222222;");
    leftTopVBoxLayout = new QVBoxLayout(leftTopArea);
    leftTopVBoxLayout->setContentsMargins(5,5,5,5);


    //Flag
    m_ppixLabelCurrency = new QPixmap(m_path);
    m_pcurrencyLabelPicture = new QLabel();
    m_pcurrencyLabelPicture->setPixmap(m_ppixLabelCurrency->scaled(60,30, Qt::KeepAspectRatio));
    m_pcurrencyLabelPicture->setAlignment(Qt::AlignCenter);


    //Currencies
    m_pnameOfcurrency = new QComboBox;
    m_pnameOfcurrency->setFixedSize(80, 30);
    QStringList ls;
    ls<<"UAH"<<"USD"<<"EUR"<<"RUB"<<"PLN"<<"JPY"<<"GBP";
    m_pnameOfcurrency->addItems(ls);

    int id = 0;
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
    connect(m_pnameOfcurrency, SIGNAL(currentTextChanged(QString)), this, SLOT(slotCurrentIndexChanged()));

    leftTopVBoxLayout->addWidget(m_pcurrencyLabelPicture);
    leftTopVBoxLayout->addWidget(m_pnameOfcurrency);


    //edit1 (topRight)
    m_pedit1 = new QLineEdit;
    m_pedit1->setMaxLength(12);
    m_pedit1->setEnabled(false);
    m_pedit1->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_pedit1->setStyleSheet("border: none;"
                           "font-size: 35px;"
                           "margin-right: 1px;");
    m_pedit1->setFixedHeight(70);


    //QHBoxLayout
    topHBoxLayout = new QHBoxLayout(this);
    topHBoxLayout->setContentsMargins(0,0,0,0);

    topHBoxLayout->addWidget(leftTopArea);
    topHBoxLayout->addWidget(m_pedit1);

    topHBoxLayout->setSpacing(0);
}

void topAreaClass::setEdit(const QString &str)
{
    m_pedit1->setText(str);
}

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


//slots
void topAreaClass::slotCurrentIndexChanged()
{
    changedFlag(m_pnameOfcurrency->currentText());
}

