#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QJSValue>
#include <QDebug>

class MyClass : public QObject {
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr)
        : QObject(parent) {}

    Q_INVOKABLE void fire() {
        qDebug() << "fire() called";
        // implementation for no arguments
    }

    Q_INVOKABLE void fire(const QJSValue& payload) {
        qDebug() << "fire(const QJSValue&) called with payload:" << payload.toString();
        // implementation for one argument
    }
};

#endif // MYCLASS_H
