#ifndef CLSWK6500P_H
#define CLSWK6500P_H

#include <QObject>
#include "singleton.h"

class clsWK6500P : public QObject
{
    Q_OBJECT
public:
    explicit clsWK6500P(QObject *parent = nullptr);

    QString getSWOption() const;
    QString getItem1() const;
    void setItem1(const QString &value);

    QString getItem2() const;
    void setItem2(const QString &value);

    QString getEqucct() const;
    void setEqucct(const QString &value);

    QString getRange() const;
    void setRange(const QString &value);

    double getFrequency() const;
    void setFrequency(double value);

    double getLevelAValue() const;
    void setLevelAValue(double value);

    double getLevelVValue() const;
    void setLevelVValue(double value);

    QString getLevelType() const;
    void setLevelType(const QString &value);

    double getBiasAValue() const;
    void setBiasAValue(double value);

    double getBiasVValue() const;
    void setBiasVValue(double value);

    QString getBiasType() const;
    void setBiasType(const QString &value);

    bool getBiasONOFF() const;
    void setBiasONOFF(bool value);

    QString getSpeed() const;
    void setSpeed(const QString &value);

    //used for GPIB process
    QString getGpibItem1() const;
    void setGpibItem1(const QString &value);

    QString getGpibItem2() const;
    void setGpibItem2(const QString &value);

    QString getGpibEqucct() const;
    void setGpibEqucct(const QString &value);

    QString getGpibRange() const;
    void setGpibRange(const QString &value);

    QString getGpibFrequency() const;
    void setGpibFrequency(const QString &value);

    QString getGpibLevelValue() const;
    void setGpibLevelValue(const QString &value);


    QString getGpibLevelType() const;
    void setGpibLevelType(const QString &value);

    QString getGpibBiasValue() const;
    void setGpibBiasValue(const QString &value);


    QString getGpibBiasType() const;
    void setGpibBiasType(const QString &value);

    QString getGpibBiasONOFF() const;
    void setGpibBiasONOFF(const QString &value);

    QString getGpibSpeed() const;
    void setGpibSpeed(const QString &value);

    QString gpibTrig();

public slots:
    void setLanRemote(bool value);


signals:
    void sgnSetItem1(QString);
    void sgnSetItem2(QString);
    void sgnSetEqucct(QString);
    void sgnSetSpeed(QString);
    void sgnSetFrequency(double);
    void sgnSetLevelType(QString);
    void sgnSetLevelValue(double);
    void sgnSetRange(QString);
    void sgnSetBiasValue(double);
    void sgnSetBiasStatus(bool value);
    void sgnSetBiasType(QString);

    void sgnSetLanRemote(bool value);
public slots:
private:
    QString item1;
    QString item2;
    QString equcct;
    QString range;
    double frequency;
    double levelAValue;
    double levelVValue;
    QString levelType;
    double biasAValue;
    double biasVValue;
    QString biasType;
    bool biasONOFF;
    QString Speed;
};

typedef Singleton <clsWK6500P> sngWK6500;
#endif // CLSWK6500P_H
