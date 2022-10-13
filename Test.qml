////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///*
import QtQuick 2.12
//import QtQuick.Window 2.12
//import QtQuick.Controls 2.12
//import QtQuick.Shapes 1.12
//import QtQuick.Dialogs 1.2
//import QtQuick.Templates 2.5

//Window {
//    visible: true
//    width: 240
//    height: 120
//    title: qsTr("Hello World")
//    Rectangle {
//        width: 240; height: 120
//        Canvas {
//            id: canvas
//            x: 10; y: 10
//            width: 100; height: 100
//            property real hue: 0.0
//            onPaint: {
//                var ctx = getContext("2d")
////                var x = 10 + Math.random(80)*80
////                var y = 10 + Math.random(80)*80
////                hue += Math.random()*0.1
////                if(hue > 1.0) { hue -= 1 }
////                ctx.globalAlpha = 0.7
////                ctx.fillStyle = Qt.hsla(hue, 0.5, 0.5, 1.0)
////                ctx.beginPath()
////                ctx.moveTo(x+5,y)
////                ctx.arc(x,y, x/10, 0, 360)
////                ctx.closePath()
////                ctx.fill()

//                ctx.drawImage("./image/map.png",0,0,100,100)

//                var ar = ctx.getImageData(0,0,100,100)
//                print('pixel length = ',ar.data.length)

//                for( var x=0; x < ar.data.length; x=x+4 )
//                {

//                    // To read RGBA values
//                    var red   =  ar.data[x];
//                    var green =  ar.data[x + 1];
//                    var blue  =  ar.data[x + 2];
//                    var alpha =  ar.data[x + 3];

//                    console.log(red + ", " + green + ", " + blue + ", " + alpha );

//                    // To convert to grey scale, modify rgba according to your formula
//                    ar.data[x]     = 0.2126 *ar.data[x]  + 0.7152* ar.data[x+1]  + 0.0722 *ar.data[x+2];
//                    ar.data[x+1]   = 0.2126 *ar.data[x]  + 0.7152* ar.data[x+1]  + 0.0722 *ar.data[x+2];
//                    ar.data[x+2]   = 0.2126 *ar.data[x]  + 0.7152* ar.data[x+1]  + 0.0722 *ar.data[x+2];
//                    ar.data[x+3]   =  255;

//                }
////                print(data)
////                for(var i in data){
////                    print(i)
////                }
////                print('data =',data)
//            }
//            MouseArea {
//                anchors.fill: parent
//                onClicked: {
//                    var url = canvas.toDataURL('image/png')
////                    print('image url=', url)

//                }
//            }
//        }

//        Image {
//            id: image
//            x: 130; y: 10
//            width: 100; height: 100
//        }

//        Timer {
//            interval: 1000
//            running: true
//            triggeredOnStart: true
//            repeat: true
//            onTriggered: canvas.requestPaint()
//        }
//    }
//}

//        Row {
//            id: colorTools
//            anchors {
//                horizontalCenter: rect_map.horizontalCenter
//                top: rect_map.top
//                topMargin: 8
//            }
//            property color paintColor: "#33B5E5"
//            spacing: 5
//            Repeater {
//                model: ["#33B5E5", "#99CC00", "#FFBB33", "#FF4444", "#111111"]
//                Rectangle {
//                    id: red
//                    width: 30
//                    height: 30
//                    color: modelData
//                    MouseArea{
//                        anchors.fill: parent
//                        onClicked: {
//                            if(color == "#111111"){
//                                colorTools.paintColor = "#FFFFFF"
//                                canvas.erase = true;
//                            }else{
//                                colorTools.paintColor = color
//                                canvas.erase = false;
//                            }

//                        }
//                    }
//                }
//            }
//        }

//        Canvas {
//            id: canvas_map
//            anchors {
//                left: parent.left
//                right: parent.right
//                top: colorTools.bottom
//                bottom: parent.bottom
//                margins: 8
//            }
//            antialiasing: true
//            property real lastX
//            property real lastY
//            property color color: colorTools.paintColor
//            property bool erase: false


//            onPaint: {
//                var ctx = getContext('2d')
//                if(erase){

//                    console.log("here");
//                    ctx.lineWidth = 10
//                    ctx.lineCap = "round"
//                    ctx.clearRect(lastX,lastY,ctx.lineWidth,ctx.lineWidth)
//                    lastX = area.mouseX
//                    lastY = area.mouseY
//                    ctx.clearRect(lastX,lastY,ctx.lineWidth,ctx.lineWidth)
//                }else{
//                    ctx.lineWidth = 1.5
//                    ctx.strokeStyle = canvas.color
//                    ctx.lineCap = "round"
//                    ctx.beginPath()
//                    ctx.moveTo(lastX, lastY)
//                    lastX = area.mouseX
//                    lastY = area.mouseY
//                    ctx.lineTo(lastX, lastY)
//                    ctx.stroke()
//                }
//            }

//            MouseArea {
//                id: area
//                anchors.fill: parent
////                    hoverEnabled: true
//                onPressed: {
//                    canvas.lastX = mouseX
//                    canvas.lastY = mouseY
//                    canvas.requestPaint()
//                }
//                onPositionChanged: {
//                    canvas.requestPaint()
//                    console.log("hhhh")
//                }

////                    onWheel: {
////                        if(wheel.angleDelta.y > 0){
////                            image_map.width=image_map.width+size_zoom
////                            image_map.height=image_map.width+size_zoom
////                        }else{
////                            if(image_map.width>rect_map.width)
////                                image_map.width= image_map.width-size_zoom
////                            if(image_map.height>rect_map.height)
////                                image_map.height= image_map.width-size_zoom
////                        }
////                        image_map.lastX = mouseX
////                        image_map.lastY = mouseY
////                        console.log(mouseX)
////                    }
//            }
//        }

//        Image{
//            id: image_map
//            width: 800
//            height: 800
//            source:"./image/map.png"
//            property int lastX: 0
//            property int lastY: 0
//            onWidthChanged: {
//                lastX = area.mouseX
//                lastY = area.mouseY
//                image_map.x = - (image_map.width - rect_map.width)*lastX/rect_map.width
//                image_map.y = - (image_map.height - rect_map.height)*lastY/rect_map.height
//            }
//        }
//        }

//*/


















////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////Window {
////    visible: true
////    width: 1920
////    height: 1080
////    title: qsTr("Hello World")
////    Rectangle {
////            x: 50; y: 50
////            width: 900; height: 600
////            color: "grey"

////            PathView {
////                id: pathView
////                anchors.fill: parent
////                model: myModel
////                delegate: myDelegate
////                dragMargin: 300

////                snapMode: PathView.SnapToItem
////                maximumFlickVelocity: width

////                preferredHighlightBegin:0.5
////                preferredHighlightEnd:0.5

////                clip: true

////                path: Path {
////                    id:flowViewPath

////                    readonly property real yCoord: pathView.height/2

////                    startX: 0
////                    startY: flowViewPath.yCoord

////                    PathAttribute{name:"elementZ"; value: 0}
////                    PathAttribute{name:"elementScale"; value: 0.3}

////                    PathLine {
////                        x: pathView.width*0.5
////                        y: flowViewPath.yCoord
////                    }

////                    PathAttribute{name:"elementZ";value:100}
////                    PathAttribute{name:"elementScale";value:1.0}

////                    PathLine {
////                        x: pathView.width
////                        y: flowViewPath.yCoord
////                    }

////                    PathAttribute{name:"elementZ";value:0}
////                    PathAttribute{name:"elementScale";value:0.3}

////                    PathPercent{value:1.0}
////                }
////            }

////            Component {
////                id: myDelegate
////                Rectangle {
////                    width: 400; height: 600
////                    color: modelColor

////                    scale: PathView.elementScale
////                    z: PathView.elementZ
////                }
////            }

////            ListModel {
////                id: myModel
////                ListElement  {modelColor: "red"}
////                ListElement  {modelColor: "green"}
////                ListElement  {modelColor: "blue"}
////                ListElement  {modelColor: "yellow"}
////                ListElement  {modelColor: "orange"}
////            }

////            Rectangle {
////                width: parent.width;
////                height: 1
////                x: 0
////                y: flowViewPath.yCoord
////                color: "black"
////            }
////        }

////}










////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////import QtQuick 2.14
////import QtQuick.Window 2.14
////import QtLocation 5.14
////import QtPositioning 5.14

////Window {
////    visible: true
////    width: 640
////    height: 480
////    property int currentIndex: -1
////    ListModel{
////        id: polygonmodel
////    }
////    Map {
////        id: map
////        anchors.fill: parent
////        plugin: Plugin {
////            name: "osm"
////        }
////        gesture.enabled: currentIndex == -1
////        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
////        zoomLevel: 14
////        MapItemView{
////            z: polygon.z + 1
////            model: polygonmodel
////            delegate: MapQuickItem{
////                anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
////                coordinate: QtPositioning.coordinate(model.coords.latitude, model.coords.longitude)
////                sourceItem: Image {
////                    width: 40
////                    height: 40
////                    source: "http://maps.gstatic.com/mapfiles/ridefinder‑images/mm_20_red.png"
////                    MouseArea{
////                        anchors.fill: parent
////                        acceptedButtons: Qt.LeftButton
////                        propagateComposedEvents: true
////                        onPressed: {
////                            currentIndex = index
////                            mouse.accepted = false
////                        }
////                    }
////                }
////            }
////        }
////        MapPolygon{
////            id: polygon
////            border.color: "green"
////            border.width: 10
////        }
////        MouseArea{
////            anchors.fill: parent
////            acceptedButtons: Qt.LeftButton | Qt.RightButton
////            onClicked: {
////                var point = Qt.point(mouse.x, mouse.y)
////                var coord = map.toCoordinate(point);
////                if (mouse.button == Qt.RightButton)
////                    addMarker(coord)
////            }
////            onPositionChanged: {
////                if (currentIndex != -1){
////                    var point = Qt.point(mouse.x, mouse.y)
////                    var coord = map.toCoordinate(point);
////                    if(coord.isValid)
////                        moveMarker(currentIndex, coord)
////                }
////            }
////            onReleased: {
////                if (mouse.button == Qt.LeftButton && currentIndex != -1){
////                    var point = Qt.point(mouse.x, mouse.y)
////                    var coord = map.toCoordinate(point);
////                    if(coord.isValid)
////                        moveMarker(currentIndex, coord)
////                    currentIndex = -1;
////                }
////            }
////        }
////    }
////    function moveMarker(index, coordinate){
////        polygonmodel.set(index, {"coords": coordinate})
////        var path = polygon.path;
////        path[index] = coordinate
////        polygon.path = path
////    }
////    function addMarker(coordinate){
////        polygonmodel.append({"coords": coordinate})
////        polygon.addCoordinate(coordinate)
////    }
////}
