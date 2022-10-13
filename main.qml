import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Shapes 1.12
import QtQml 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Templates 2.5
import QtLocation 5.14
import QtPositioning 5.14
import "."
import io.qt.Supervisor 1.0

Window {
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Hello World")
    flags: Qt.Window | Qt.FramelessWindowHint
    visibility: Window.FullScreen

    property int tool_num: 0
    property int map_size: 800
    property int size_zoom: 0
    property int brush_size: 10
    property int index: 0
    property list<Item> array_canvas;
    property list<Item> array_brush;
    property var map_data;
    property string image_source: "./build/image/map.png"

    onMap_dataChanged: {
        canvas_map.requestPaint()
    }

    Supervisor{
        id:supervisor
    }
    Rectangle{
        id: btn_save
        width: 100
        height: 50
        x: 1200
        y: 300
        color: "gray"
        Text{
            anchors.centerIn: parent
            text: "save"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                var ctx = canvas_map.getContext('2d');
                size_zoom = 0;
                area_map.moveX = 0;
                area_map.moveY = 0;
                ctx.drawImage(image_map,0,0,map_size,map_size);
                canvas_map.requestPaint();
                canvas_map.save("image/map1.png")
            }
        }
    }
    Rectangle{
        id: btn_tool1
        width: 100
        height: 50
        x: 1200
        y: 400
        color: "gray"
        Text{
            anchors.centerIn: parent
            text: "draw"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                tool_num = 1;
            }
        }
    }
    Rectangle{
        id: btn_tool2
        width: 100
        height: 50
        x: 1200
        y: 500
        color: "gray"
        Text{
            anchors.centerIn: parent
            text: "erase"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                tool_num = 2;
            }
        }
    }
    Rectangle{
        id: btn_tool3
        width: 100
        height: 50
        x: 1400
        y: 300
        color: "gray"
        Text{
            anchors.centerIn: parent
            text: "move"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                tool_num = 0;




                //debug




            }
        }
    }

    Rectangle{
        id: rect_map
        width: 800
        height: 800
        clip: true
//        fillMode: Image.PreserveAspectCrop
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left;
        anchors.leftMargin: 200

        property int flag_image: 0
        border.width: 3
        border.color:"black"

        Canvas{
            id: canvas_map
            x: 0; y:0;
            width: image_map.width
            height: image_map.height
            antialiasing: true

            property real lastX
            property real lastY
            property var vlastX:({})
            property var vlastY:({})
//            scale: 1
            property var index: 0
            onPaint:{
                if(tool_num == 1){
                    var ctx = getContext("2d")
                    ctx.lineWidth = 1.5
                    ctx.strokeStyle = "red"
                    ctx.lineCap = "round"
                    ctx.beginPath()
                    ctx.moveTo(lastX, lastY)
                    lastX = area_map.mouseX
                    lastY = area_map.mouseY
                    vlastX[index++] = lastX;
                    print(vlastX.toString());
                    ctx.lineTo(lastX, lastY)
                    ctx.stroke()
                }

            }
            Behavior on scale{
                NumberAnimation{
                    duration: 300
                }
            }
            onXChanged: {
                requestPaint();
            }
            onYChanged: {
                requestPaint();
            }
            onScaleChanged: {
                if(canvas_map.x  > canvas_map.width*(canvas_map.scale - 1)/2){
                    canvas_map.x = canvas_map.width*(canvas_map.scale - 1)/2
                }else if(canvas_map.x < -(canvas_map.width*(canvas_map.scale - 1)/2 + canvas_map.width - rect_map.width)){
                    canvas_map.x = -(canvas_map.width*(canvas_map.scale - 1)/2 + canvas_map.width - rect_map.width)
                }

                if(canvas_map.y  > canvas_map.height*(canvas_map.scale - 1)/2){
                    canvas_map.y = canvas_map.height*(canvas_map.scale - 1)/2
                }else if(canvas_map.y < -(canvas_map.height*(canvas_map.scale - 1)/2 + canvas_map.height - rect_map.height)){
                    canvas_map.y = -(canvas_map.height*(canvas_map.scale - 1)/2 + canvas_map.height - rect_map.height)
                }
            }

            MouseArea{
                id: area_map
                anchors.fill: parent
                property var tempPath;

                property var moveX : 0;
                property var moveY : 0;
                property var dmoveX : 0;
                property var dmoveY : 0;
                property var startX : 0;
                property var startY : 0;
                property bool is_pressed : false;
                hoverEnabled: tool_num==0?true:false

                onWheel: {
                    if(tool_num == 0){
                        var ctx = canvas_map.getContext('2d');
                        var new_scale;
                        wheel.accepted = false;
                        if(wheel.angleDelta.y > 0){
                            new_scale = canvas_map.scale + 0.3;
                            if(new_scale > 5){
                                canvas_map.scale = 5;
                            }else{
                                canvas_map.scale = new_scale;
                            }
                        }else{
                            new_scale = canvas_map.scale - 0.3;
                            if(new_scale < 1){
                                canvas_map.scale = 1;
                            }else{
                                canvas_map.scale = new_scale;
                            }
                        }
                        print(canvas_map.scale,canvas_map.width,canvas_map.height,canvas_map.x,canvas_map.y)
                        canvas_map.requestPaint()
                    }

                }

                onPressed: {
                    is_pressed = true;
                    startX = mouseX;
                    startY = mouseY;
                    canvas_map.lastX = mouseX;
                    canvas_map.lastY = mouseY;
                    if(tool_num == 1){

                    }
                }
                onReleased: {
                    is_pressed = false;
                    if(tool_num == 0){
                        moveX = moveX+dmoveX;
                        moveY = moveY+dmoveY;
                    }
                }
                onPositionChanged: {
                    var ctx = canvas_map.getContext('2d');
                    if(is_pressed){
                        if(tool_num == 0){//move
                            dmoveX = (mouseX - startX);
                            dmoveY = (mouseY - startY);

                            canvas_map.x += dmoveX;
                            canvas_map.y += dmoveY;

                            if(canvas_map.x  > canvas_map.width*(canvas_map.scale - 1)/2){
                                canvas_map.x = canvas_map.width*(canvas_map.scale - 1)/2
                            }else if(canvas_map.x < -(canvas_map.width*(canvas_map.scale - 1)/2 + canvas_map.width - rect_map.width)){
                                canvas_map.x = -(canvas_map.width*(canvas_map.scale - 1)/2 + canvas_map.width - rect_map.width)
                            }

                            if(canvas_map.y  > canvas_map.height*(canvas_map.scale - 1)/2){
                                canvas_map.y = canvas_map.height*(canvas_map.scale - 1)/2
                            }else if(canvas_map.y < -(canvas_map.height*(canvas_map.scale - 1)/2 + canvas_map.height - rect_map.height)){
                                canvas_map.y = -(canvas_map.height*(canvas_map.scale - 1)/2 + canvas_map.height - rect_map.height)
                            }

                        }else if(tool_num == 1){

                        }
                        canvas_map.requestPaint()
                    }else{

                    }
                }
            }
        }
        Timer {
            interval: 1000
            running: true
            triggeredOnStart: true
            repeat: true
            onTriggered: {
                if(canvas_map.available && rect_map.flag_image == 0){
                    rect_map.flag_image = 1;
                    var ctx = canvas_map.getContext('2d');
                    ctx.drawImage(image_map,0,0,image_map.width,image_map.height)
                    map_data = ctx.getImageData(0,0,image_map.width,image_map.height)
                    print('image size = ',image_map.width, image_map.height)
                    print('pixel length = ',map_data.data.length)
//                    for( var x=0; x < map_data.data.length; x=x+4 )
//                    {

////                         To read RGBA values
//                        var red   =  map_data.data[x];
//                        var green =  map_data.data[x + 1];
//                        var blue  =  map_data.data[x + 2];
//                        var alpha =  map_data.data[x + 3];

//                        print(red + ", " + green + ", " + blue + ", " + alpha );

////                         To convert to grey scale, modify rgba according to your formula
//                        map_data.data[x]     = 0.2126 *map_data.data[x]  + 0.7152* map_data.data[x+1]  + 0.0722 *map_data.data[x+2];
//                        map_data.data[x+1]   = 0.2126 *map_data.data[x]  + 0.7152* map_data.data[x+1]  + 0.0722 *map_data.data[x+2];
//                        map_data.data[x+2]   = 0.2126 *map_data.data[x]  + 0.7152* map_data.data[x+1]  + 0.0722 *map_data.data[x+2];
//                        map_data.data[x+3]   =  255;
//                    }
//                    print(map_data.data)
                }

//                canvas_map.requestPaint()
            }
        }
        }

        Image{
            id: image_map
            visible: false
            source:image_source
        }
    }




