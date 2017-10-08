#ifndef CLSWK6500PUI_H
#define CLSWK6500PUI_H

#include <QObject>
#include "ui_frmWK6500PUi.h"
#include <QMouseEvent>

class frmWK6500PUi : public QDialog, private Ui::frmWK6500PUi
{
    Q_OBJECT
public:
   explicit frmWK6500PUi(QWidget *parent=0);
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);


private slots:
    void reSetupUi(QObjectList list);

    void on_btnItem1_clicked();

    void on_btnQuit_clicked();

    void on_btnItem2_clicked();

    void on_btnEqucct_clicked();

    void on_btnSpeed_clicked();

    void on_btnFrequency_clicked();

    void on_btnLevel_clicked();

    void on_btnRange_clicked();

    void on_btnBiasValue_clicked();

    void on_btnBiasType_clicked();

    void on_btnBiasStatus_clicked();

    void on_btnRepeat_clicked();

    void on_btnTrig_clicked();
private slots:
    void connectSlots();
private:
    bool mMoving;
    QPoint mMovePosition;

};

#endif // CLSWK6500PUI_H
