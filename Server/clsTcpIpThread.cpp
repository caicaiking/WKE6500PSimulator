#include "clsTcpIpThread.h"

clsTcpIpThread::clsTcpIpThread(int Id, QObject *parent):
        QThread(parent)
{
   this->socketDescriptor = Id;
}

void clsTcpIpThread::run()
{
    qDebug()<<this->socketDescriptor<< " " "Starting thread";

    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug()<< this->socketDescriptor << " Client connected";

    exec();
}

void clsTcpIpThread::readRead()
{
   QByteArray data = socket->readAll();

   if(data.contains("\r\n")|| data.contains("\n"))
   {
       QString tmpData = QString(data);
       tmpData = tmpData.remove("\r");
       tmpData = tmpData.remove("\n");
       emit getCommand(tmpData);
   }
}

void clsTcpIpThread::disconnected()
{
    qDebug()<< socketDescriptor << " disconnected";
    socket->deleteLater();
    exit(0);
}

void clsTcpIpThread::write(QString str)
{
   str+= "\n";

   socket->write(str.toStdString().c_str());
   socket->flush();
}

int clsTcpIpThread::getSocketDescriptor() const
{
    return socketDescriptor;
}
