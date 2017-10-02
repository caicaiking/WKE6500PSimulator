#ifndef CLSMAINWINDOW_H
#define CLSMAINWINDOW_H

#include "ui_clsMainWindow.h"
#include "clsWK6500MServer.h"
class clsMainWindow : public QMainWindow, private Ui::clsMainWindow
{
    Q_OBJECT

public:
    explicit clsMainWindow(QWidget *parent = 0);
private slots:


    void on_btnTrig_clicked();

public slots:
private:
};

#endif // CLSMAINWINDOW_H
