#ifndef CLSWKCOMMANDPROCESS_H
#define CLSWKCOMMANDPROCESS_H

#include <QObject>
#include <QDebug>
#include "clsWK6500MServer.h"
#include "singleton.h"
#include <QMap>

class clsWKCommandProcess : public QObject
{
    Q_OBJECT
public:
    explicit clsWKCommandProcess(QObject *parent = nullptr);
    void setIsRemote(bool value);

    typedef void (clsWKCommandProcess::* QUERY_FUNCTION)();
    typedef void (clsWKCommandProcess::* SET_FUNCTION)(QString);


signals:
    void writeToClient(QString str);
    void lanRemote(bool value);
public slots:
    void setGpibCommand(QString str);


    void queryId();
    void querySpeed();
    void queryEquCCT();
    void queryFunc1();
    void queryFunc2();

    void setSpeed(QString value);
    void setEqucct(QString value);
    void setFunc1(QString value);
    void setFunc2(QString value);




private:
    QMap<QString, QUERY_FUNCTION> queryFunction;
    QMap<QString, SET_FUNCTION> setFunction;
};

typedef Singleton < clsWKCommandProcess> sngWkCommandProcess;
#endif // CLSWKCOMMANDPROCESS_H
