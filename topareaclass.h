#ifndef TOPAREACLASS_H
#define TOPAREACLASS_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QComboBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QRegularExpression>
#include <QStringList>
#include <QPushButton>
#include <QFontDatabase>
#include <QSettings>

#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonObject>

const int WINDOWWIDTH = 360;
const int WINDOWWHIGHT = 560;

class topAreaClass : public QWidget
{
    Q_OBJECT
public:
    explicit topAreaClass(QString path, QWidget *parent = nullptr);

    void setEdit(const QString& str);
    void setStartId();
    void clear();
    void changedFlag(QString currency);

    QString getM_edit1Text();
    QString getCurrency();
    QString preparing;

private slots:
    void slotCurrentIndexChanged();
private:
    QString      m_path;

    QWidget*     topArea;
    QWidget*     leftTopArea;

    QHBoxLayout* topHBoxLayout;
    QVBoxLayout* leftTopVBoxLayout;

    QPixmap*     m_ppixLabelCurrency;
    QLabel*      m_pcurrencyLabelPicture;

    QComboBox*   m_pnameOfcurrency;
    int id = 0;

    QLineEdit*   m_pedit;

};

#endif // TOPAREACLASS_H
