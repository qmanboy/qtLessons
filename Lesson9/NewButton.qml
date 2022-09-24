import QtQuick 2.0
import QtQuick.Controls 2.12

Button {
    contentItem: Text {
        text: add.text
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: add.down ? 'white' : 'black'
    }
    background:
    Rectangle {
        implicitHeight: main.allHeight
        color: main.color
        Rectangle {
            anchors.bottomMargin: marginNum;
            anchors.rightMargin: marginNum;
            anchors.leftMargin: marginNum + 1;
            anchors.topMargin: marginNum;
            anchors.fill: parent
            /*border.color: 'grey'
            border.width: 1*/
            implicitHeight: main.allHeight
            color: add.down ? '#A9A9A9' : 'grey'
            opacity: add.down ? 0.5 : 1
            radius: 2
        }
    }
}
