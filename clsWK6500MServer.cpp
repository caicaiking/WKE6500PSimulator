#include "clsWK6500MServer.h"
#include "MyThread.h"
#include <QDebug>
#include "clsWKCommandProcess.h"
clsWK6500MServer::clsWK6500MServer(QObject *parent) :QTcpServer(parent)
{

}

void clsWK6500MServer::startServer()
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

clsWK6500MServer::~clsWK6500MServer()
{
   QMapIterator <int, MyThread * > it (pool);

   while(it.hasNext())
   {
       it.next().value()->exit(0);
   }
}

void clsWK6500MServer::incomingConnection(int socketDescriptor)
{
    qDebug()<< socketDescriptor << " comming..." ;

    MyThread * thread  = new MyThread(socketDescriptor,this);
    pool.insert(socketDescriptor, thread);

    emit lanRemote(true);
    connect(thread,SIGNAL(getCommand(QString)),sngWkCommandProcess::Instance(),SLOT(setGpibCommand(QString)));
    connect(sngWkCommandProcess::Instance(),SIGNAL(writeToClient(QString)),thread,SLOT(write(QString)));

    connect(thread,&MyThread::destroyed,[=]{

        int id = thread->getSocketDescriptor();
        pool.remove(id);

    });
    connect (thread,SIGNAL(finished()),thread,SLOT(deleteLater()));

    connect(thread,&MyThread::finished,[=]()
    {
        qDebug()<< socketDescriptor << " Lan remote off";
        emit lanRemote(false);
    });
    thread->start();
}
