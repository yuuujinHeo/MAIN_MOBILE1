import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml 2.12
import "."
import io.qt.Supervisor 1.0

Item {
    id: page_kitchen
    objectName: "page_kitchen"
    width: 1280
    height: 800

    property int tray_num: 3
    property double battery: 0
    property date curDate: new Date()
    property string curTime: curDate.toLocaleTimeString()

    property int table_num1: 0
    property int table_num2: 0
    property int table_num3: 0

    property int tray_width: 250
    property int tray_height: 100
    property int tray_dist: 80

    property int cur_table_num: 0
    property bool flag_moving: false

    Timer{
        id: timer_update
        interval: 100
        running: true
        repeat: true
        onTriggered: {
            curTime = Qt.formatTime(new Date(), "hh:mm")
        }
    }

    Rectangle{
        anchors.fill : parent
        color: "white"
    }

//    ListView{
//        x: 100
//        width: 600
//        height: 100
//        model: tables
//        delegate: compo_table
//        orientation: ListView.Horizontal
//        spacing: 10
//        interactive: true
//        focus: true
//    }

//    ListModel{
//        id: tables
//        ListElement{
//            table_num: 1
//        }
//        ListElement{
//            table_num: 2
//        }
//        ListElement{
//            table_num: 3
//        }
//        ListElement{
//            table_num: 4
//        }
//        ListElement{
//            table_num: 5
//        }
//        ListElement{
//            table_num: 6
//        }
//    }

//    Component{
//        id: compo_table
//        Rectangle{
//            width: 70
//            height: 70
//            color: "gray"
//            Text{
//                anchors.centerIn: parent
//                text: table_num
//            }
//            MouseArea{
//                anchors.fill: parent
//                onPressed: {
//                    flag_moving = true;
//                    cur_table_num = table_num
//                }
//            }
//        }
//    }

//    Rectangle{
//        id: curTable
//        width: 70
//        height: 70
//        color: "gray"
//        visible: flag_moving
//        x: mouse_moving.mouseX
//        y: mouse_moving.mouseY
//        Text{
//            anchors.centerIn: parent
//            text: cur_table_num
//        }
//    }
    property int init_x_table : 400
    property int init_y_table : 10
    property int spacing_table : 10
    Repeater{
        model: 6
        Rectangle{
            id: rect_table
            width:70
            height:70
            z: mouse_table.drag.active || mouse_table.pressed ? 2:1
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
            x: init_x_table + spacing_table*index + 70*index
            y: init_y_table
            property point beginDrag
            property bool caught: false
            border{width:2;color:"white"}
            radius:7
            Drag.active: mouse_table.drag.active

            onYChanged: {
                if(flag_moving){
                    if(x>tray_1.x && x<tray_1.x+tray_1.width){
                        if(y>tray_1.y && y<tray_1.y+tray_1.height){
                            if(table_num1 != cur_table_num){
                                console.log("UI : SET TABLE 1 TO "+Number(cur_table_num));
                                tray_1.color = rect_table.color;
                                table_num1 = cur_table_num;
                            }
                        }else if(y>tray_2.y && y<tray_2.y+tray_2.height){
                            if(table_num2 != cur_table_num){
                                console.log("UI : SET TABLE 2 TO "+Number(cur_table_num));
                                tray_2.color = rect_table.color;
                                table_num2 = cur_table_num;
                            }
                        }else if(y>tray_3.y && y<tray_3.y+tray_3.height){
                            if(table_num3 != cur_table_num){
                                console.log("UI : SET TABLE 3 TO "+Number(cur_table_num));
                                tray_3.color = rect_table.color;
                                table_num3 = cur_table_num;
                            }
                        }
                    }
                }
            }
            onXChanged: {
                if(flag_moving){
                    if(x>tray_1.x && x<tray_1.x+tray_1.width){
                        if(y>tray_1.y && y<tray_1.y+tray_1.height){
                            if(table_num1 != cur_table_num){
                                console.log("UI : SET TABLE 1 TO "+Number(cur_table_num));
                                tray_1.color = rect_table.color;
                                table_num1 = cur_table_num;
                            }
                        }else if(y>tray_2.y && y<tray_2.y+tray_2.height){
                            if(table_num2 != cur_table_num){
                                console.log("UI : SET TABLE 2 TO "+Number(cur_table_num));
                                tray_2.color = rect_table.color;
                                table_num2 = cur_table_num;
                            }
                        }else if(y>tray_3.y && y<tray_3.y+tray_3.height){
                            if(table_num3 != cur_table_num){
                                console.log("UI : SET TABLE 3 TO "+Number(cur_table_num));
                                tray_3.color = rect_table.color;
                                table_num3 = cur_table_num;
                            }
                        }
                    }
                }
            }

            Text{
                anchors.centerIn: parent
                text: index+1
                color: "white"
            }
            MouseArea{
                id:mouse_table
                anchors.fill:parent
                drag.target: parent
                propagateComposedEvents: true
                preventStealing: false
                onPressed: {
                    rect_table.beginDrag = Qt.point(rect_table.x, rect_table.y);
                    cur_table_num = index+1;
                    flag_moving = true;
                }
                onReleased: {
                    flag_moving = false;
                    backAnimX.from = rect_table.x;
                    backAnimX.to = beginDrag.x;
                    backAnimY.from = rect_table.y;
                    backAnimY.to = beginDrag.y;
                    backAnim.start()

                }
            }
            ParallelAnimation{
                id: backAnim
                SpringAnimation{ id: backAnimX; target: rect_table; property: "x"; duration: 500; spring: 2; damping: 0.2}
                SpringAnimation{ id: backAnimY; target: rect_table; property: "y"; duration: 500; spring: 2; damping: 0.2}
            }
        }
    }



    MouseArea{
        id: mouse_moving
        anchors.fill: parent
        enabled: flag_moving
        onPressAndHold: {
            console.log(mouseX,mouseY)
        }
        onReleased: {
            flag_moving = false;
        }
    }

    Rectangle{
        id: tray_1
        width: tray_width
        height: tray_height
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.top: parent.top
        anchors.topMargin: 200
        color: "blue"
        border{width:2;color:"black"}
        radius:7
        onColorChanged: {
            console.log(color)
            if(color != "#0000ff"){
                ani_tray_1.start()
            }
        }
        SequentialAnimation{
            id: ani_tray_1
            running: false
            ParallelAnimation{
                NumberAnimation{target:tray_1; property:"scale"; from:1;to:1.2;duration:300;}
                NumberAnimation{target:tray_1; property:"scale"; from:1.2;to:1;duration:300;}
            }
        }

        MouseArea{
            id: mtray_1
            anchors.fill: parent
            onClicked:{
                table_num1 = 0;
                tray_1.color =  "blue"
            }
        }
        Text{
            id: textTray1
            anchors.centerIn: parent
            text: table_num1==0?"":Number(table_num1)
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.top
            anchors.bottomMargin: 10
            font.pixelSize: 30
            text: "TRAY 1"
        }
    }

    Rectangle{
        id: tray_2
        width: tray_width
        height: tray_height
        anchors.left: tray_1.left
        anchors.top: tray_1.bottom
        anchors.topMargin: tray_dist
        color: "blue"
        border{width:2;color:"black"}
        radius:7
        onColorChanged: {
            console.log(color)
            if(color != "#0000ff"){
                ani_tray_2.start()
            }
        }
        SequentialAnimation{
            id: ani_tray_2
            running: false
            ParallelAnimation{
                NumberAnimation{target:tray_2; property:"scale"; from:1;to:1.2;duration:300;}
                NumberAnimation{target:tray_2; property:"scale"; from:1.2;to:1;duration:300;}
            }
        }
        MouseArea{
            id: mtray_2
            anchors.fill: parent
            onClicked:{
                table_num2 = 0;
                tray_2.color= "blue"
            }
        }


        Text{
            id: textTray2
            anchors.centerIn: parent
            text: table_num2==0?"":Number(table_num2)
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.top
            anchors.bottomMargin: 10
            font.pixelSize: 30
            text: "TRAY 2"
        }
    }
    Rectangle{
        id: tray_3
        width: tray_width
        height: tray_height
        anchors.left: tray_2.left
        anchors.top: tray_2.bottom
        anchors.topMargin: tray_dist
        color: "blue"
        border{width:2;color:"black"}
        radius:7
        onColorChanged: {
            console.log(color)
            if(color != "#0000ff"){
                ani_tray_3.start()
            }
        }
        SequentialAnimation{
            id: ani_tray_3
            running: false
            ParallelAnimation{
                NumberAnimation{target:tray_3; property:"scale"; from:1;to:1.2;duration:300;}
                NumberAnimation{target:tray_3; property:"scale"; from:1.2;to:1;duration:300;}
            }
        }
        MouseArea{
            id: mtray_3
            anchors.fill: parent
            onClicked:{
                table_num3 = 0;
                tray_3.color= "blue"
            }
        }
        Text{
            id: textTray3
            anchors.centerIn: parent
            text: table_num3==0?"":Number(table_num3)
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.top
            anchors.bottomMargin: 10
            font.pixelSize: 30
            text: "TRAY 3"
        }
    }

    Rectangle{
        id: rect_go
        width: 100
        height: 100
        anchors.top: parent.top
        anchors.topMargin: 300
        anchors.right: parent.right
        anchors.rightMargin: 150
        color: "gray"
        Text{
            id: text_go
            anchors.centerIn: parent
            text: "GO"
        }
        MouseArea{
            id: btn_go
            anchors.fill: parent
            onClicked: {
                console.log("GO : "+Number(table_num1)+","+Number(table_num2)+","+Number(table_num3));
                supervisor.setTray(table_num1,table_num2,table_num3);
            }
        }
    }

    Rectangle{
        width: 300
        height: 50
        anchors.right: parent.right
        color: "red"

        Text{
            id: textTime
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 20
            text: curTime

        }
        Text{
            id: textBattery
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 20
            text: Number(battery)+' V'
        }
    }

}
