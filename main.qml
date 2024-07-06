import QtQuick 2.14
import QtQuick.Controls 2.14

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    Component.onCompleted: {
        // Call the no-argument function
        myObject.fire()

        // Call the function with a QJSValue argument
        var payload = { key: "value" }
        myObject.fire(payload)
    }
}
