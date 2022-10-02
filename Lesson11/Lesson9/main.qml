import QtQuick 2.4
import QtQml 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3



Window {
    id: main
    minimumWidth: 640
    maximumWidth: 640
    minimumHeight: theHeight
    maximumHeight: theHeight
    height: theHeight
    visible: true
    title: qsTr("ToDoList")
    color: '#A9A9A9'
    property int theHeight: newTask.isOpen ? tasks.height + lay.height + add.height + newTask.height : tasks.height + lay.height + add.height
    property int allHeight: 35
    property color borderColor: 'grey'
    property color fontColor: 'white'
    property int marginNum: 1
    property date dDate: new Date()
    property string curDate
    Component.onCompleted: {
        curDate = dDate.toLocaleDateString(Qt.locale(), Locale.ShortFormat)
    }

    Rectangle {
        id: lay
        width: main.width
        height: main.allHeight
        color: labelArea.pressed ? main.color : 'grey'
        border.width: 2
        border.color: labelArea.pressed ? 'grey' : main.color
        radius: 2
        Label {
            id: label
            width: parent.width
            height: parent.height
            Text {
                width: parent.width
                height: parent.height
                text: newTask.isCalendarOpened ? qsTr("Выберите дату") : qsTr("Отобразить текущие задачи")
                color: labelArea.pressed ? 'black' : 'white'
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea {
                id: labelArea
                width: parent.width
                height: parent.height
                enabled: !newTask.isCalendarOpened
                onClicked: {
                    MainCore.openTable()
                }
            }
        }
    }

    Rectangle {
        id: newTask
        width: main.width
        height: main.allHeight

        property bool isOpen: false
        property bool isCalendarOpened: calendar.visible
        property string curDate: Qt.formatDate(calendar.selectedDate, "dd.MM.yyyy")

        signal calendarOpened()
        signal calendarClosed()

        anchors.top: tasks.bottom
        visible: isOpen
        Rectangle {
            id: taskRec
            border.color: "grey"
            height: parent.height
            width: parent.width/4*2
            anchors.left: parent.left
            radius: 2
            TextField {
                id: taskInput
                anchors.fill: parent
                anchors.right: parent.right
                verticalAlignment: TextInput.AlignVCenter
                activeFocusOnTab: true
                placeholderText: qsTr("Задача")
            }
        }
        Rectangle {
            id: dateRec
            border.color: "grey"
            height: parent.height
            width: parent.width/4
            anchors.left: taskRec.right
            radius: 2
            TextField {
                id: deadlineInput
                anchors.fill: parent
                readOnly: true
                verticalAlignment: TextInput.AlignVCenter
                activeFocusOnTab: true
                text: Qt.formatDate(calendar.selectedDate, "dd.MM.yyyy")
                MouseArea {
                id: deadlineInputArea
                    height: parent.height
                    width: parent.width
                    onClicked: {
                        newTask.isCalendarOpened ? calendar.close() : calendar.open()
                    }
                }
            }

        }
        ComboBox {
            id: progressCombo
            model: ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]
            height: parent.height
            width: parent.width/4
            anchors.left: dateRec.right
        }

    }



    Rectangle {
        y: lay.height
        id:tasks
        width: main.width        
        anchors.top : lay.bottom
        height: newTask.isCalendarOpened ? 400 : 0
        //anchors.bottom: newTask.isOpen ? newTask.top : add.top
        Calendar {
            id: calendar
            visible: false
            anchors.fill: parent
            dayOfWeekFormat: Locale.ShortFormat
            onClicked: {
                calendar.close()
            }
            function open() {
                calendar.visible = true
            }
            function close() {
                calendar.visible = false
            }
        }
    }

    NewButton {
        id:add
        text: newTask.isOpen ? qsTr("Закрыть") : qsTr("Новая задача")
        anchors.top: newTask.isOpen ? newTask.bottom : tasks.bottom
        background.implicitWidth: main.width/2

        onClicked: {
            if (newTask.isOpen === false) {
                taskInput.focus = true
                calendar.close()
                newTask.isOpen = true
            }
            else
            {
                taskInput.text = ""
                progressCombo.currentIndex = 0
                newTask.isOpen = false
            }
        }        
    }

    Rectangle {
        y: add.y
        height: main.allHeight
        width: main.width/2
        anchors.left: add.right
        color: main.color
        Button {
            id:add2
            anchors.bottomMargin: marginNum - 1.2;
            anchors.rightMargin: marginNum;
            anchors.leftMargin: marginNum - 1.2;
            anchors.topMargin: marginNum - 1.2;
            anchors.fill: parent
            enabled: newTask.isOpen ? true : false
            opacity: add2.enabled ? 1 : 0.3
            Text {
                id: txt
                height: add2.height
                width: add2.width
                text: qsTr("Добавить")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            onClicked: {
                if (newTask.isOpen === true) {
                    if (taskInput.text.length === 0 || deadlineInput.text.length === 0) {
                        return
                    }
                    calendar.close()
                    MainCore.addTask(taskInput.text, deadlineInput.text, progressCombo.currentText.toString());
                    taskInput.text = ""
                    progressCombo.currentIndex = 0
                    newTask.isOpen = false
                }
            }
        }
    }
}
