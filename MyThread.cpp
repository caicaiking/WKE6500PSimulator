#include "MyThread.h"

MyThread::MyThread(int Id, QObject *parent):
        QThread(parent)
{
   this->socketDescriptor = Id;
}

void MyThread::run()
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

void MyThread::readRead()
{
   QByteArray data = socket->readAll();

   if(data.contains("\r\n"))
   {
       emit getCommand(data.remove(data.length()-2,2));
   }
}

void MyThread::disconnected()
{
    qDebug()<< socketDescriptor << " disconnected";
    socket->deleteLater();
    exit(0);
}

void MyThread::write(QString str)
{
   str+= "\n";

   socket->write(str.toStdString().c_str());
   socket->flush();
}

int MyThread::getSocketDescriptor() const
{
    return socketDescriptor;
}
