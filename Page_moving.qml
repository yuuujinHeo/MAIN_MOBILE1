import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml 2.12

Item {
    id: page_moving
    objectName: "page_moving"
    width: 1280
    height: 800

    property string pos: "1번테이블"
    property bool robot_paused: false


    Text{
        id: target_pos
        text: pos
        font.pixelSize: 50
        font.bold: true
        color: "blue"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 150
    }
    Text{
        id: text_mention
        text: "(으)로 이동 중입니다."
        font.pixelSize: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top : target_pos.bottom
        anchors.topMargin: 30
    }
    Rectangle{
        id: rect_moving
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: text_mention.bottom
        anchors.topMargin: 40
        width: ani_moving.width;
        height: ani_moving.height;
        AnimatedImage{
            id: ani_moving
            source: Qt.resolvedUrl("qrc:/image/robot_moving.gif")
            width: 350;
            height: 350;
            paused: robot_paused
        }
    }
    Popup{
        id: popup_pause
        width: 200
        height: 150
        anchors.centerIn: parent
        dim: true
        background: Rectangle{
            color:"gray"
        }
        opacity: 0.6
        Text{
            anchors.centerIn: parent
            text: "일시정지"
        }
        MouseArea{
            id: btn_page_popup
            anchors.fill: parent
            onClicked: {
                if(robot_paused){
                    console.log("UI : RESUME");
                    popup_pause.close()
                    robot_paused = false;
                }else{
                    console.log("UI : PAUSE");
                    robot_paused = true;
                    popup_pause.open();

                }
            }
        }
    }
    MouseArea{
        id: btn_page
        anchors.fill: parent
        onClicked: {
            if(robot_paused){
                console.log("UI : RESUME");
                popup_pause.close()
                robot_paused = false;
            }else{
                console.log("UI : PAUSE");
                robot_paused = true;
                popup_pause.open();

            }
        }
    }
}
