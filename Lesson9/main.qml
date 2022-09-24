import QtQuick 2.4
import QtQml 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3



Window {
    id: main
    width: 640
    height: 480
    visible: true
    title: qsTr("ToDoList")
    color: '#A9A9A9'
    property int allHeight: 35
    property color borderColor: 'grey'
    property color fontColor: 'white'
    property int marginNum: 1
    property date dDate: new Date()
    property string curDate
    Component.onCompleted: {
        curDate = dDate.toLocaleDateString(Qt.locale(), Locale.ShortFormat)
    }

    function createModel()
    {
        for (var i = 0; i < MainCore.getItemCount(); i++)
        {
            mymodel.append({"task":     MainCore.getTask(i),
                            "deadline": MainCore.getDeadLine(i),
                            "progress": MainCore.getProgress(i)})
        }
    }

    Rectangle {
        id: lay
        width: main.width
        height: 40
        color: 'grey'
        border.width: 1
        border.color: borderColor
        Label {
            id: label
            anchors.fill: parent
            Text {
                width: parent.width
                height: parent.height
                text: newTask.isCalendarOpened ? qsTr("Выберите дату") : qsTr("Текущие задачи")
                color: 'white'
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
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

        anchors.bottom: add.top
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
        anchors.bottom: newTask.isOpen ? newTask.top : add.top
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
                table.visible = false
            }
            function close() {
                calendar.visible = false
                table.visible = true
            }
        }

        ListModel {
            id: mymodel
        }

        ListView {
            id: table
            width: parent.width
            height:  parent.height
            model: mymodel
            delegate: delegateID

            Component {
                id: delegateID
                Rectangle{
                    width: parent.width
                    height: 60
                    Rectangle {
                        id: colRec
                        border.color: borderColor
                        anchors.topMargin: 5
                        anchors.leftMargin: 5
                        anchors.rightMargin: 5
                        anchors.fill:parent
                        radius: 5
                        color: "lightsteelblue"
                        Item {
                             Column {
                                 id: col
                                 width: parent.width - 5;
                                 anchors.right: parent.right
                                 Text { text: '<b>Задача:</b> ' + task}
                                 Text { text: '<b>Дата окончания выполнения:</b> ' + deadline}
                                 Text { text: '<b>Прогресс:</b> ' + progress }
                             }
                         }
                    }
                }
            }
        }
    }

    NewButton {
        id:add
        text: newTask.isOpen ? qsTr("Закрыть") : qsTr("Новая задача")
        y: main.height - add.height
        background.implicitWidth: main.width/2

        onClicked: {
            if (newTask.isOpen === false) {
                taskInput.focus = true
                calendar.close()
                newTask.isOpen = true
                table.currentIndex = -1;
                table.currentIndex = mymodel.count - 1;
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
        y: main.height - add.height
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
                    mymodel.append({"task": taskInput.text, "deadline": deadlineInput.text, "progress":progressCombo.currentText.toString()})
                    MainCore.addTask(taskInput.text, deadlineInput.text, progressCombo.currentText.toString());
                    taskInput.text = ""
                    progressCombo.currentIndex = 0
                    newTask.isOpen = false
                    table.currentIndex = mymodel.count - 1;
                }
            }
        }
    }
}
