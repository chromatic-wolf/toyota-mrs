import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt3D.Core
import Qt3D.Render
import QtQuick3D
import QtQuick3D.Helpers
import QtQuick.Dialogs
import QtQuick.Scene3D

import Qt3D.Input
import Qt3D.Extras
import QtQuick.Controls.Material







Window{
    visible: true
    id: root
    width: Screen.width
    height: Screen.height





    Rectangle {
        id: rectangle
        width: Screen.width
        height: Screen.height

        color: "#c2c2c2"








        Button {
            id: button
            objectName: "myButton"
            text: qsTr("Press me")
            anchors.verticalCenter: parent.verticalCenter
            checkable: true
            anchors.horizontalCenter: parent.horizontalCenter

            signal qmlPressed()
           onClicked: button.qmlPressed()

            Connections {
                target: button
                onClicked: animation.start()
            }
        }

        Button
        {

            id: shutdownBtn
            objectName: "shutdownBtn"
            text: qsTr("Exit")
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 408
            anchors.bottomMargin: 27
            signal exitPressed()
           onClicked: shutdownBtn.exitPressed()
        }

        Text {
            id: label
            text: qsTr("Hello Dashboard")
            anchors.top: button.bottom
            anchors.topMargin: 45
            anchors.horizontalCenter: parent.horizontalCenter

            SequentialAnimation {
                id: animation

                ColorAnimation {
                    id: colorAnimation1
                    target: rectangle
                    property: "color"
                    to: "#2294c6"
                    from: "#c2c2c2"
                }

                ColorAnimation {
                    id: colorAnimation2
                    target: rectangle
                    property: "color"
                    to: "#c2c2c2"
                    from: "#2294c6"
                }
            }
        }

        Image {
            id: car_img
            objectName: "myCar"

            property bool running: false
            visible: true
            width: 394
            height: 340
            source: "qrc:///assets/car.png"
            fillMode: Image.PreserveAspectFit
            anchors.top: button.bottom
            anchors.topMargin: -444
            anchors.horizontalCenter: parent.horizontalCenter
            RotationAnimation on rotation{
                objectName: "myAnimation"
                target: car_img
                from: 0
                to: 360
                duration: 3000
                running: car_img.running
            }

        }

        Slider {
            id: slider
            objectName: "mySlider"
            from: 0
            to: 100
            value: 50
            anchors.bottom: label.bottom
            anchors.bottomMargin: -72
            anchors.horizontalCenter: label.horizontalCenter
             signal qmlSignal(msg: int)
            onMoved: slider.qmlSignal(slider.value)

        }




        states: [
            State {
                name: "clicked"
                when: button.checked

                PropertyChanges {
                    target: label
                    text: qsTr("Button Checked")
                }
            }
        ]
    }
}
