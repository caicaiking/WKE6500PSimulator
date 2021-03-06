#include "frmWK6500PUi.h"
#include <QApplication>
#include "clsWKServer.h"
#include "clsWKCommandProcess.h"
#include "ScreenHelper.h"
#include <QScreen>
#include "clsWK6500P.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    sngWK6500::Instance();

    frmWK6500PUi w;
    w.resize(sngSH::Instance()->dp(1)*640,
             sngSH::Instance()->dp(1)*480);
    w.move((qApp->primaryScreen()->size().width()-w.width())/2,
           (qApp->primaryScreen()->size().height()-w.height())/2);
    w.show();

    clsWKServer server;
    QObject::connect(&server, &clsWKServer::lanRemote,[=](bool value){
        sngWkCommandProcess::Instance()->setIsRemote(value);
    });

    server.startServer();

    return a.exec();
}
