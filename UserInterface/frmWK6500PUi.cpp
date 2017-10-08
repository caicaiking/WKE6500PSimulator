#include "frmWK6500PUi.h"
#include "doubleType.h"
#include "clsWK6500P.h"
#include <QObjectList>
#include "ScreenHelper.h"
#include <QDebug>
#include <QRect>
frmWK6500PUi::frmWK6500PUi(QWidget *parent): QDialog(parent)
{
    this->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMaximizeButtonHint);
    reSetupUi(this->children());

    wgdLanRemote->raise();
    lblLanRemote->setVisible(false);
    btnSaveNorm1->setEnabled(false);
    btnSaveNorm2->setEnabled(false);
    wgdLanRemote->setVisible(false);
    wgdBiasON->setVisible(false);
    btnTrig->setFocus();

    connectSlots();

}

void frmWK6500PUi::mousePressEvent(QMouseEvent *event)
{
    mMoving = true;
    mMovePosition = event->globalPos()-pos();

    return QDialog::mousePressEvent(event);

}

void frmWK6500PUi::mouseMoveEvent(QMouseEvent *event)
{
    if(mMoving && (event->buttons() && Qt::LeftButton) && (event->globalPos().manhattanLength()> QApplication::startDragDistance()))
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos()-pos();
    }
    return QDialog::mouseMoveEvent(event);

}

void frmWK6500PUi::mouseReleaseEvent(QMouseEvent *event)
{

    mMoving= false;
    return QWidget::mouseReleaseEvent(event);
}
void frmWK6500PUi::on_btnItem1_clicked()
{
    qDebug()<<"ssss";
}

void frmWK6500PUi::on_btnQuit_clicked()
{
    this->close();
}

void frmWK6500PUi::reSetupUi(QObjectList list)
{
    qreal px = sngSH::Instance()->dp(1);

    QPushButton *b;
    QFrame *f;
    QWidget *w;
    QLabel *l;
    QGroupBox *g;

    foreach (QObject *tmpObx, list)
    {
        QString typeName= tmpObx->metaObject()->className();
        //qDebug()<<typeName;

        if(typeName == "QPushButton")
        {

            b= qobject_cast<QPushButton*>(tmpObx);
            if(b)
            {
                QRect rec= b->geometry();
                rec = QRect(rec.left()*px,
                            rec.top()*px,
                            rec.width()*px,
                            rec.height()*px);
                QFont font = b->font();
                font.setPointSize(font.pointSize()*px);
                b->setFont(font);

                b->setGeometry(rec);
            }
        }
        else if(typeName == "QFrame")
        {

            f= qobject_cast<QFrame*>(tmpObx);
            if(f)
            {
                QRect rec= f->geometry();
                rec = QRect(rec.left()*px,
                            rec.top()*px,
                            rec.width()*px,
                            rec.height()*px);

                f->setGeometry(rec);
                reSetupUi(f->children());
            }
        }
        else if(typeName == "QWidget")
        {
            w= qobject_cast<QWidget*>(tmpObx);
            if(w)
            {
                QRect rec= w->geometry();
                rec = QRect(rec.left()*px,
                            rec.top()*px,
                            rec.width()*px,
                            rec.height()*px);

                w->setGeometry(rec);
                reSetupUi(w->children());
            }
        }
        else if(typeName == "QLabel")
        {
            l= qobject_cast<QLabel*>(tmpObx);
            if(l)
            {
                QRect rec= l->geometry();
                rec = QRect(rec.left()*px,
                            rec.top()*px,
                            rec.width()*px,
                            rec.height()*px);
                QFont font = l->font();
                font.setPointSize(font.pointSize()*px);
                l->setFont(font);

                l->setGeometry(rec);
            }

        }
        else if(typeName == "QGroupBox")
        {
            g= qobject_cast<QGroupBox*>(tmpObx);
            if(l)
            {
                QRect rec= g->geometry();
                rec = QRect(rec.left()*px,
                            rec.top()*px,
                            rec.width()*px,
                            rec.height()*px);

                g->setGeometry(rec);

                QFont font = g->font();
                font.setPointSize(font.pointSize()*px);
                g->setFont(font);


                reSetupUi(g->children());
            }

        }
    }

}


void frmWK6500PUi::on_btnItem2_clicked()
{
    btnItem1->blockSignals(true);
}

void frmWK6500PUi::on_btnEqucct_clicked()
{

}

void frmWK6500PUi::on_btnSpeed_clicked()
{

}

void frmWK6500PUi::on_btnFrequency_clicked()
{

}

void frmWK6500PUi::on_btnLevel_clicked()
{

}

void frmWK6500PUi::on_btnRange_clicked()
{

}

void frmWK6500PUi::on_btnBiasValue_clicked()
{

}

void frmWK6500PUi::on_btnBiasType_clicked()
{

}

void frmWK6500PUi::on_btnBiasStatus_clicked()
{

    sngWK6500::Instance()->setBiasONOFF(!sngWK6500::Instance()->getBiasONOFF());
}

void frmWK6500PUi::on_btnRepeat_clicked()
{
}

void frmWK6500PUi::on_btnTrig_clicked()
{

}

void frmWK6500PUi::connectSlots()
{
    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetLanRemote,[=](bool vis){
        wgdLanRemote->setVisible(vis);
        lblLanRemote->setVisible(vis);
        btnItem1->blockSignals(vis);
    });

    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetItem1,[=](QString text) { btnItem1->setText(text); });
    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetItem2,[=](QString text) { btnItem2->setText(text); });
    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetEqucct,[=](QString text) { btnEqucct->setText(text); });
    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetSpeed,[=](QString text) { btnSpeed->setText(text); });
    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetRange,[=](QString text) { btnRange->setText(text); });
    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetFrequency,[=](double value) {
        doubleType dt;
        dt.setData(value);
        btnFrequency->setText(dt.formateToString()+"Hz");
    });

    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetLevelType,[=](QString type)
    {
        doubleType dt;
        if(type == tr("Current"))
        {
            dt.setData(sngWK6500::Instance()->getLevelAValue());
            btnLevel->setText(dt.formateToString()+"A");
        }
        else
        {
            dt.setData(sngWK6500::Instance()->getLevelVValue());
            btnLevel->setText(dt.formateToString()+"V");
        }
    });

    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetLevelValue,[=](double value){
        QString type = sngWK6500::Instance()->getLevelType();
        doubleType dt;
        if(type== tr("Current"))
        {
            dt.setData(value);
            btnLevel->setText(dt.formateToString()+"A");
        }
        else
        {
            dt.setData(value);
            btnLevel->setText(dt.formateToString()+"V");

        }
    });

    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetBiasValue,[=](double value){
        QString type = sngWK6500::Instance()->getBiasType();
        doubleType dt;
        if(type ==tr("Current"))
        {
            dt.setData(value);
            btnBiasValue->setText(dt.formateToString(5)+"A");
        }
        else
        {
            dt.setData(value);
            btnBiasValue->setText(dt.formateToString(5)+"V");
        }

    });

    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetBiasType,[=](QString type){
        doubleType dt;

        if(type==tr("Current"))
        {
            dt.setData(sngWK6500::Instance()->getBiasAValue());
            btnBiasValue->setText(dt.formateToString(5)+"A");
        }
        else
        {
            dt.setData(sngWK6500::Instance()->getBiasVValue());
            btnBiasValue->setText(dt.formateToString(5)+"V");
        }

        btnBiasType->setText(type);
    });

    connect(sngWK6500::Instance(),&clsWK6500P::sgnSetBiasStatus,[=](bool value){
        if(value)
        {
            btnBiasStatus->setText(tr("ON"));
        }
        else
        {
            btnBiasStatus->setText(tr("OFF"));
        }

        this->wgdBiasON->setVisible(value);
    });

}
