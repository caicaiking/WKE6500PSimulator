#include <QMap>
#include "clsWK6500P.h"

clsWK6500P::clsWK6500P(QObject *parent) : QObject(parent)
{
    item1 = "Z";
    item2 = "A";
    equcct = tr("串连");
    range = tr("自动");
    frequency = 1000.0;
    levelAValue = 0.01;
    levelVValue = 1.0;
    levelType = tr("电压");
    biasAValue = 0.0;
    biasVValue =0.0;
    biasType = tr("电流");
    biasONOFF = false;
    Speed = tr("最快");
}

QString clsWK6500P::getSWOption() const
{
    /*
*OPT? reads the hardware options. Returns D1 or D2

*OPT2? reads the s/w options
The result byte is defined as follows:

Bit 0 = MM mode
Bit 1 = EC mode
Bit 2 = Unused
Bit 3 = Polar/complex
Bit 4 = Materials test
Bit 5 = Advanced Res Search

    */

    return "0";
}

QString clsWK6500P::getItem1() const
{
    return item1;
}

void clsWK6500P::setItem1(const QString &value)
{
    item1 = value;
}

QString clsWK6500P::getItem2() const
{
    return item2;
}

void clsWK6500P::setItem2(const QString &value)
{
    item2 = value;
}

QString clsWK6500P::getEqucct() const
{
    return equcct;
}

void clsWK6500P::setEqucct(const QString &value)
{
    equcct = value;
}

QString clsWK6500P::getRange() const
{
    return range;
}

void clsWK6500P::setRange(const QString &value)
{
    range = value;
}

double clsWK6500P::getFrequency() const
{
    return frequency;
}

void clsWK6500P::setFrequency(double value)
{
    frequency = value;
}

double clsWK6500P::getLevelAValue() const
{
    return levelAValue;
}

void clsWK6500P::setLevelAValue(double value)
{
    levelAValue = value;
}

double clsWK6500P::getLevelVValue() const
{
    return levelVValue;
}

void clsWK6500P::setLevelVValue(double value)
{
    levelVValue = value;
}

QString clsWK6500P::getLevelType() const
{
    return levelType;
}

void clsWK6500P::setLevelType(const QString &value)
{
    levelType = value;
}

double clsWK6500P::getBiasAValue() const
{
    return biasAValue;
}

void clsWK6500P::setBiasAValue(double value)
{
    biasAValue = value;
}

double clsWK6500P::getBiasVValue() const
{
    return biasVValue;
}

void clsWK6500P::setBiasVValue(double value)
{
    biasVValue = value;
}

QString clsWK6500P::getBiasType() const
{
    return biasType;
}

void clsWK6500P::setBiasType(const QString &value)
{
    biasType = value;
}

bool clsWK6500P::getBiasONOFF() const
{
    return biasONOFF;
}

void clsWK6500P::setBiasONOFF(bool value)
{
    biasONOFF = value;
}

QString clsWK6500P::getSpeed() const
{
    return Speed;
}

void clsWK6500P::setSpeed(const QString &value)
{
    Speed = value;
}

QString clsWK6500P::getGpibItem1() const
{
    QString items = "LCQDRXZYθBG";
    int index = items.indexOf(item1);
    if(index >=0)
    {
        return QString::number(index);
    }
    else
    {
        return tr("查询Item1错误");
    }

}

void clsWK6500P::setGpibItem1(const QString &value)
{
    QString items = "LCQDRXZYBG";


    if(items.contains(value)|| (value  == "ANGLE"))
    {
        if(value =="ANGLE")
        {
            setItem1("θ");
        }
        else
        {
            setItem1(value);
        }
    }
}

QString clsWK6500P::getGpibItem2() const
{
    QString items = "LCQDRXZYθBG";
    int index = items.indexOf(item2);
    if(index >=0)
    {
        return QString::number(index);
    }
    else
    {
        return tr("查询Item2错误");
    }
}

void clsWK6500P::setGpibItem2(const QString &value)
{
    QString items = "LCQDRXZYBG";


    if(items.contains(value)|| (value  == "ANGLE"))
    {
        if(value =="ANGLE")
        {
            setItem2("θ");
        }
        else
        {
            setItem2(value);
        }
    }

}

QString clsWK6500P::getGpibEqucct() const
{
    QStringList pars;
    pars << tr("串联");
    pars << tr("并联");

    int index = pars.indexOf(this->equcct);
    if(index >=0)
    {
        return QString::number(index);
    }
    else
    {
        return tr("查询等效电路错误");
    }

}

void clsWK6500P::setGpibEqucct(const QString &value)
{
    QMap<QString,QString> pars;
    pars.insert("SER",tr("串联"));
    pars.insert("PAR",tr("并联"));

    if(pars.keys().contains(value))
    {
        setEqucct(pars.value(value));
    }
}

QString clsWK6500P::getGpibRange() const
{
    QStringList pars;
    pars << tr("自动");
    pars << "1";
    pars << "2";
    pars << "3";
    pars << "4";
    pars << "5";
    pars << "6";
    pars << "7";

    int index = pars.indexOf(this->range);
    if(index >=0)
    {
        return QString::number(index);
    }
    else
    {
        return tr("查询Range错误");
    }

}

void clsWK6500P::setGpibRange(const QString &value)
{
    QMap<QString,QString> pars;
    pars.insert("AUTO",tr("自动"));
    pars.insert("1","1");
    pars.insert("2","2");
    pars.insert("3","3");
    pars.insert("4","4");
    pars.insert("5","5");
    pars.insert("6","6");
    pars.insert("7","7");
    if(pars.keys().contains(value))
    {
        setRange(pars.value(value));
    }
}

QString clsWK6500P::getGpibFrequency() const
{
    return QString::number(this->frequency,'E',7);
}

void clsWK6500P::setGpibFrequency(const QString &value)
{
    bool ok;
    value.toDouble(&ok);

    if(ok)
    {
        setFrequency(value.toDouble());
    }
}

QString clsWK6500P::getGpibLevelValue() const
{
    if(this->levelType == tr("电压"))
    {
        return QString::number(this->levelVValue,'E',7);
    }
    else
    {
        return QString::number(this->levelAValue,'E',7);
    }

}

void clsWK6500P::setGpibLevelValue(const QString &value)
{
    QString tmpValue = value;
    if(value.contains("A"))
    {
        QString avalue = tmpValue.remove("A");
        bool ok;
        avalue.toDouble(&ok);
        if(ok)
        {
            setLevelAValue(avalue.toDouble());
            setLevelType(tr("电流"));
        }
    }
    else if(value.contains("V"))
    {
        QString vvalue = tmpValue.remove("V");
        bool ok;
        vvalue.toDouble(&ok);
        if(ok)
        {
            setLevelVValue(vvalue.toDouble());
            setLevelType(tr("电压"));
        }
    }
    else
    {
        bool ok;
        tmpValue.toDouble(&ok);

        if(ok)
        {
            if(this->levelType == tr("电压"))
            {
                setLevelVValue(tmpValue.toDouble());
                setLevelType(tr("电压"));
            }
            else
            {
                setLevelAValue(tmpValue.toDouble());
                setLevelType(tr("电流"));
            }
        }

    }
}

QString clsWK6500P::getGpibLevelType() const
{
    QStringList pars;
    pars << tr("电压") << tr("电流");

    int index  = pars.indexOf(this->levelType);

    if(index>= 0 )
    {
        return QString::number(index);
    }
    else
    {
        return tr("查询LevelType错误");
    }
}

QString clsWK6500P::getGpibBiasValue() const
{
    if(biasType == tr("电压"))
    {
        return QString::number(biasVValue,'E',7);
    }
    else
    {
        return QString::number(biasAValue,'E',7);
    }
}

void clsWK6500P::setGpibBiasValue(const QString &value)
{
    bool ok;
    value.toDouble(&ok);

    if(ok)
    {
        if(biasType == tr("电压"))
        {
            setBiasVValue(value.toDouble());
        }
        else
        {
            setBiasAValue(value.toDouble());
        }
    }
}

QString clsWK6500P::getGpibBiasType() const
{
    QStringList pars;
    pars<<tr("电流")<< tr("电压");
    int index = pars.indexOf(this->biasType);

    if(index >=0)
    {
        return QString::number(index);
    }
    else
    {
        return tr("查询Bias 类型错误");
    }
}

void clsWK6500P::setGpibBiasType(const QString &value)
{
    if(value == "VOL")
    {
        this->setBiasType(tr("电压"));
    }
    else if(value == "CUR")
    {
        this->setBiasType(tr("电流"));
    }
    else
    {
        //Send wrong parameter to here.
    }
}

QString clsWK6500P::getGpibBiasONOFF() const
{
    if(this->biasONOFF)
    {
        return QString::number(1);
    }
    else
    {
        return QString::number(0);
    }
}

void clsWK6500P::setGpibBiasONOFF(const QString &value)
{
    if(value == "ON")
    {
        this->setBiasONOFF(true);
    }
    else
    {
        this->setBiasONOFF(false);
    }
}

QString clsWK6500P::getGpibSpeed() const
{
    if(this->Speed==tr("最快"))
    {
        return QString::number(-4);
    }

    if(this->Speed == tr("快速"))
    {
        return QString::number(-3);
    }

    if(this->Speed == tr("中速"))
    {
        return QString::number(-2);
    }

    if (this->Speed == tr("慢速"))
    {
        return QString::number(-1);
    }

    return this->Speed; //This is a number value 1-256
}

void clsWK6500P::setGpibSpeed(const QString &value)
{
    QString tmpSpeed="";
    if(QString("MAXimum").contains(value))
    {
        tmpSpeed =tr("最快");
    }
    else if(QString("FAST").contains(value))
    {
        tmpSpeed = tr("快速");
    }
    else if(QString("MEDium").contains(value))
    {
        tmpSpeed = tr("中速");
    }
    else if(QString("SLOW").contains(value))
    {
        tmpSpeed = tr("慢速");
    }
    else
    {
        bool ok;
        value.toInt(&ok);

        if(ok)
        {
            tmpSpeed = value;
        }
    }

    if(!tmpSpeed.isEmpty())
        setSpeed(tmpSpeed);
}

QString clsWK6500P::gpibTrig()
{
    return "1E2,3.00E3";
}
