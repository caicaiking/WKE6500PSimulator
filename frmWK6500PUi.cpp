#include "frmWK6500PUi.h"
#include <QObjectList>
#include "ScreenHelper.h"
#include <QDebug>
#include <QRect>
frmWK6500PUi::frmWK6500PUi(QWidget *parent): QDialog(parent)
{
    this->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMaximizeButtonHint | Qt::WindowStaysOnTopHint);
    reSetupUi(this->children());

    btnTrig->setFocus();

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
    qDebug()<<"I clicked";
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
