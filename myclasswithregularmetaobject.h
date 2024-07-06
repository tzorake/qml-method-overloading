#ifndef MYCLASSWITHREGULARMETAOBJECT_H
#define MYCLASSWITHREGULARMETAOBJECT_H

#include <QObject>
#include <QJSValue>
#include <QDebug>
#include <private/qqmlopenmetaobject_p.h>

class MyClassWithRegularMetaObject : public QObject
{
    Q_OBJECT
public:
    explicit MyClassWithRegularMetaObject(QObject *parent = nullptr)
        : QObject(parent)
        , m_metaObject(new QQmlOpenMetaObject(this))
    {}

    Q_INVOKABLE void fire() {
        qDebug() << "fire() called";
        // implementation for no arguments
    }

    Q_INVOKABLE void fire(const QJSValue& payload) {
        qDebug() << "fire(const QJSValue&) called with payload:" << payload.toString();
        // implementation for one argument
    }

private:
    QQmlOpenMetaObject *m_metaObject;
};

#endif // MYCLASSWITHREGULARMETAOBJECT_H
