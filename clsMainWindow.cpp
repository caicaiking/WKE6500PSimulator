#include "clsMainWindow.h"
#include "clsWKCommandProcess.h"

clsMainWindow::clsMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

}

void clsMainWindow::on_btnTrig_clicked()
{
    sngWkCommandProcess::Instance()->writeToClient("1.003E-9,2.3E1");
}
