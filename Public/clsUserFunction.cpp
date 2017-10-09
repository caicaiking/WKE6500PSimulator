#include "clsUserFunction.h"
#include <QObject>

clsUserFunction::clsUserFunction()
{

}
QString clsUserFunction::getSuffix(const QString &value)
{

    if (value=="Z" || value=="R" || value=="X" || value=="RDC" || value =="Rdc")
        return QString("Ω");

    if(value=="A" || value==QString("θ"))
        return QString("°");


    if(value=="G" || value=="B" || value=="Y")
        return "S";

    if(value=="E'r" || value=="E\"r" || value=="U'r" || value=="U\"r")
        return "U";

    if(value =="De" || value == "Du")
        return "D";

    if(value=="L")
        return "H";
    if(value=="C")
        return "F";
    if(value=="Q" || value=="D")
        return value;
    if(value.toUpper()=="FREQUENCY" || value.toUpper()==QObject::tr("频率").toUpper())
        return "Hz";
    if(value.toUpper() =="SRF")
        return "Hz";
    if(value.toUpper()=="BIAS" || value.toUpper()==QObject::tr("偏置电压").toUpper() || value.toUpper()==QObject::tr("外置偏压").toUpper() || value.toUpper()==QObject::tr("电压信号"))
        return "V";
    if(value.toUpper()=="TIME" || value.toUpper()==QObject::tr("时间").toUpper())
        return "s";

    if(value.toUpper()=="BIASI" || value.toUpper()==QObject::tr("偏置电流").toUpper())
        return "A";
    if(value.toUpper()=="LEVELA" || value.toUpper()==QObject::tr("电流信号").toUpper())
        return "A";
    if(value.toUpper() == QObject::tr("次数").toUpper())
        return "T";
    if(value.toUpper()=="LEVELV")
        return "V";

    return value;
}
