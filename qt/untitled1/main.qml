import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    BorderImage {
        id: borderImage1
        x: 439
        y: 182
        width: 136
        height: 100
        border.left: -3
        clip: false
        source: "../../../../Pictures/Wallpapers/DanielSimon_TronLegacy_LightRunner_wallpaper1920.jpg"
    }

    Item {
        id: item1
        x: 222
        y: 11
        width: 207
        height: 117
    }

    Button {
        id: button1
        x: 35
        y: 114
        text: qsTr("Button")

        Button {
            id: button2
            x: 0
            y: 46
            text: qsTr("Button")
        }
    }

    Slider {
        id: sliderHorizontal1
        x: 35
        y: 205
    }
}
