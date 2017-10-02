#include "clsWKCommandProcess.h"
#include <QDebug>
#include <QStringListIterator>


clsWKCommandProcess::clsWKCommandProcess(QObject *parent) : QObject(parent)
{
    //注册所有的函数，用其GPIB指令注册其Key
    queryFunction.insert("*IDN?",this->queryId);
    queryFunction.insert("SPEED?",this->querySpeed);
    queryFunction.insert("EQU-CCT?",this->queryEquCCT);
    queryFunction.insert("FUNC:1?",this->queryFunc1);
    queryFunction.insert("FUNC:2?",this->queryFunc2);

    setFunction.insert("SPEED", this->setSpeed);
    setFunction.insert("EQU-CCT", this->setEqucct);
    setFunction.insert("FUNC:1",this->setFunc1);
    setFunction.insert("FUNC:2",this->setFunc2);
}

void clsWKCommandProcess::setIsRemote(bool value)
{
    emit lanRemote(value);
}

void clsWKCommandProcess::setGpibCommand(QString str)
{
    QString strMode1st, strMode2end;

    QStringList cmdList = str.split(";",QString::SkipEmptyParts);

    QListIterator<QString> it(cmdList);

    while(it.hasNext())
    {
        QString tmpStr = it.next();

        if(!tmpStr.isEmpty())
        {
            if(str.contains("?"))
            {
                QStringList modes= str.split(":",QString::SkipEmptyParts);
                if(modes.length()==1 && queryFunction.keys().contains(modes.at(0)))
                {

                    (this->*(queryFunction.value(modes.at(0))))();
                }
                else if( modes.length()==2 && queryFunction.keys().contains(modes.at(1)))
                {

                    (this->*(queryFunction.value(modes.at(1))))();
                }
                else if(modes.length()==3 && queryFunction.keys().contains(modes.at(1)+":"+modes.at(2)))
                {

                    (this->*(queryFunction.value(modes.at(1)+":"+modes.at(2))))();
                }
                else
                {
                    writeToClient("Send Command error!");
                }

            }
            else
            {
                QStringList pars = tmpStr.split(" ",QString::SkipEmptyParts);

                if(pars.length()==1)
                {
                    QStringList modes = pars.at(0).split(":",QString::SkipEmptyParts);
                    if(modes.length()==1 && setFunction.keys().contains(modes.at(0)))
                        (this->*(setFunction.value(modes.at(0))))("");
                    else if(modes.length()==2 && setFunction.keys().contains(modes.at(1)))
                        (this->*(setFunction.value(modes.at(1))))("");
                    else
                    {
                        writeToClient("Send Command error!");
                    }

                }
                else if(pars.length()==2)
                {
                    QString par = pars.at(1);
                    QString strMode = pars.at(0);
                    QStringList modes = strMode.split(":",QString::SkipEmptyParts);

                    if(modes.length()==3)
                    {
                        strMode1st = modes.at(0);
                        strMode2end = modes.at(1);
                        QString strItem = modes.at(2);

                        if(setFunction.keys().contains(strMode2end+":"+strItem))
                        {
                            (this->*(setFunction.value(strMode2end+":"+strItem)))(par);
                        }
                    }
                    else if(modes.length() ==2)
                    {
                        strMode1st = modes.at(0);
                        strMode2end = modes.at(1);

                        if(setFunction.keys().contains(strMode2end))
                        {
                            (this->*(setFunction.value(strMode2end)))(par);
                        }
                    }
                    else if(modes.length()==1)
                    {
                        if(setFunction.keys().contains(strMode2end+":"+modes.at(0)))
                        {
                            (this->*(setFunction.value(strMode2end+":"+modes.at(0))))(par);

                        }
                    }
                    else
                    {
                        writeToClient("Send Command error!");
                    }
                }
            }
        }
    }
}

void clsWKCommandProcess::setSpeed(QString value)
{
    qDebug()<<value;
}

void clsWKCommandProcess::setEqucct(QString value)
{

    qDebug()<<value;
}

void clsWKCommandProcess::setFunc1(QString value)
{

    qDebug()<<value;
}

void clsWKCommandProcess::setFunc2(QString value)
{

    qDebug()<<value;
}

void clsWKCommandProcess::queryId()
{
    writeToClient("WAYNE KERR, 65120P, Simulator-Abama, 0.1");
}

void clsWKCommandProcess::querySpeed()
{

   writeToClient("MAX");
}

void clsWKCommandProcess::queryEquCCT()
{

   writeToClient("SER");
}

void clsWKCommandProcess::queryFunc1()
{

   writeToClient("Z");
}

void clsWKCommandProcess::queryFunc2()
{
   writeToClient("A");
}


