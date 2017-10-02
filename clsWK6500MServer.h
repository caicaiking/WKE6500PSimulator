#ifndef CLSWK6500MSERVER_H
#define CLSWK6500MSERVER_H
#include "MyThread.h"
#include <QTcpServer>
#include <QList>
class clsWK6500MServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit  clsWK6500MServer(QObject *parent=0);
    void startServer();
    ~clsWK6500MServer();

protected:
    void incomingConnection(int socketDescriptor);
signals:
    void lanRemote(bool value);
public slots:

private:
    QMap<int, MyThread *> pool;
};

#endif // CLSWK6500MSERVER_H
