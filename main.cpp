#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "myclass.h"
#include "myclasswithregularmetaobject.h"
#include "myclasswithcustommetaobject.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    if (true) {
        engine.rootContext()->setContextProperty("myObject", QVariant::fromValue(new MyClass));
    }
    if (false) {
        engine.rootContext()->setContextProperty("myObject", QVariant::fromValue(new MyClassWithRegularMetaObject));
    }
    if (false) {
        engine.rootContext()->setContextProperty("myObject", QVariant::fromValue(new MyClassWithCustomMetaObject));
    }
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
