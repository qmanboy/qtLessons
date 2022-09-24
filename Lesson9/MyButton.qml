import QtQuick 2.0
import QtQuick.Controls 2.12

Button {
    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        color: colorButton.down ? 'black' : 'red'
    }
}
