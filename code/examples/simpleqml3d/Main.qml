import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Scene3D


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")




    ColumnLayout {

        height: 480
        width: 320

        Rectangle{
        Layout.fillWidth: true
        height: 75

        color: "#41CD52"

        Label {
            text: "Iron man"
            color: "white"
            anchors.fill: parent
            font.pixelSize: 20
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth: true
        }
        }

        Rectangle {
            id: scene
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "white"

            Scene3D {
                id: scene3d
                anchors.fill: parent
                anchors.margins: 10
                focus: true
                aspects: ["input", "logic"]
                cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

                //Loading ThreeDimensionalScene.qml for better code style
                ThreeDimensionalScene{}
            }
        }

        Item{
            Layout.fillWidth: true
            height: 50

        }


    }

}
