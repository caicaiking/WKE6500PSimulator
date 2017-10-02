#include "clsMainWindow.h"
#include <QApplication>
#include "clsWK6500MServer.h"
#include "clsWKCommandProcess.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    clsWK6500MServer server;
    QObject::connect(&server, &clsWK6500MServer::lanRemote,[=](bool value){
        sngWkCommandProcess::Instance()->setIsRemote(value);
    });

    server.startServer();


    clsMainWindow w;
    w.show();

    return a.exec();
}
