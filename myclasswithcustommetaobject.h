#ifndef MYCLASSWITHCUSTOMMETAOBJECT_H
#define MYCLASSWITHCUSTOMMETAOBJECT_H

#include <QObject>
#include <QJSValue>
#include <QDebug>
#include <private/qqmlopenmetaobject_p.h>

class MetaObject : public QQmlOpenMetaObject
{
public:
    MetaObject(QObject* object, const QMetaObject* metaObject)
        : QQmlOpenMetaObject(object, metaObject)
        , m_object(object)
    {
        Q_UNUSED(m_object);
    }

    virtual ~MetaObject()
    {
    }

private:
    QObject* m_object;
};

class MyClassWithCustomMetaObject : public QObject
{
    Q_OBJECT
public:
    explicit MyClassWithCustomMetaObject(QObject *parent = nullptr)
        : QObject(parent)
        , m_metaObject(new MetaObject(this, &staticMetaObject))
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
    MetaObject *m_metaObject;
};

#endif // MYCLASSWITHCUSTOMMETAOBJECT_H
