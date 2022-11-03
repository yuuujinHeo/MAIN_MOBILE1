import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml 2.12

Item {
    id: page_pickup
    objectName: "page_pickup"
    width: 1280
    height: 800

    property string pos: "1번"

    Text{
        id: target_pos
        text: pos + "트레이"
        font.pixelSize: 50
        font.bold: true
        color: "blue"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 150
    }
    Text{
        id: text_mention
        text: "의 제품을 수령해주세요."
        font.pixelSize: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top : target_pos.bottom
        anchors.topMargin: 30
    }
    Text{
        id: text_hello
        text:"감사합니다."
        visible: false
        font.pixelSize: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top : target_pos.bottom
        anchors.topMargin: 30
    }

    Rectangle{
        id: rect_confirm
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: text_mention.bottom
        anchors.topMargin: 100
        width: 300;
        height: 200;
        color: "blue"
        Text{
            text: "확인"
            font.pixelSize: 40

            anchors.centerIn: parent
        }
        MouseArea{
            id: btn_confirm
            anchors.fill: parent
            onClicked: {
                //check loadcell?
                console.log("UI : CONFIRM");
                text_mention.visible = false;
                target_pos.visible = false;
                text_hello.visible = true;
                rect_confirm.visible = false;
                rect_hello.visible = true;
                timer_hello.start();
            }
        }
    }

    Timer{
        id: timer_hello
        interval: 3000
        running: false
        repeat: false
        onTriggered: {
            console.log("UI : MOVE NEXT");
        }
    }

    Rectangle{
        id: rect_hello
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: text_mention.bottom
        anchors.topMargin: 40
        width: ani_hello.width;
        height: ani_hello.height;
        visible: false
        AnimatedImage{
            id: ani_hello
            source: Qt.resolvedUrl("qrc:/image/robot_hello.gif")
            width: 350;
            height: 350;
        }
    }
}
