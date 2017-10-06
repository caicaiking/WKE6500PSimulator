#ifndef CLSWK6500MSERVER_H
#define CLSWK6500MSERVER_H
#include "MyThread.h"
#include <QTcpServer>
#include <QList>
class clsWKServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit  clsWKServer(QObject *parent=0);
    void startServer();
    ~clsWKServer();

protected:
    void incomingConnection(int socketDescriptor);
signals:
    void lanRemote(bool value);
public slots:

private:
    QMap<int, MyThread *> pool;
};

#endif // CLSWK6500MSERVER_H
