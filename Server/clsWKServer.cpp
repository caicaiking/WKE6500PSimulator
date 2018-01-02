#include "clsWKServer.h"
#include "clsTcpIpThread.h"
#include <QDebug>
#include "clsWKCommandProcess.h"
clsWKServer::clsWKServer(QObject *parent) :QTcpServer(parent)
{
}

void clsWKServer::startServer()
{
    if(!this->listen(QHostAddress::Any,2000))
    {
        qDebug()<< "Could not start server";
    }
    else
    {
        qDebug()<< "listening....";
    }
}

clsWKServer::~clsWKServer()
{
   QMapIterator <int, clsTcpIpThread * > it (pool);

   while(it.hasNext())
   {
       it.next().value()->exit(0);
   }
}

void clsWKServer::incomingConnection(int socketDescriptor)
{
    qDebug()<< socketDescriptor << " comming..." ;

    clsTcpIpThread * thread  = new clsTcpIpThread(socketDescriptor,this);
    pool.insert(socketDescriptor, thread);

    emit lanRemote(true);
    connect(thread,SIGNAL(getCommand(QString)),sngWkCommandProcess::Instance(),SLOT(setGpibCommand(QString)));
    connect(sngWkCommandProcess::Instance(),SIGNAL(writeToClient(QString)),thread,SLOT(write(QString)));

    connect(thread,&clsTcpIpThread::destroyed,[=]{

        int id = thread->getSocketDescriptor();
        pool.remove(id);

    });
    connect (thread,SIGNAL(finished()),thread,SLOT(deleteLater()));

    connect(thread,&clsTcpIpThread::finished,[=]()
    {
        qDebug()<< socketDescriptor << " Lan remote off";
        emit lanRemote(false);
    });
    thread->start();
}
