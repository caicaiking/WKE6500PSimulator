#ifndef SCREENHELPER_H
#define SCREENHELPER_H

#include <QObject>
#include "singleton.h"
class ScreenHelper : public QObject
{
    Q_OBJECT
public:
    explicit ScreenHelper(QObject *parent = nullptr);
    Q_INVOKABLE qreal dp(const qreal &size);
signals:

private:
    const qreal m_DPI;
public slots:
};

typedef Singleton< ScreenHelper> sngSH;
#endif // SCREENHELPER_H
