

/*
    Copyright 2020, Mitch Curtis

    This file is part of Slate.

    Slate is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Slate is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Slate. If not, see <http://www.gnu.org/licenses/>.
*/
import QtQuick 2.12
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
// TODO: remove in Qt 6
import QtQml 2.15

import App 1.0

import "." as Ui

Panel {
    id: root
    objectName: "historyPanel"
    title: qsTr("History")
    topPadding: 0
    leftPadding: 0
    rightPadding: 0
    bottomPadding: 5

    property ImageCanvas canvas
    property Project project

    readonly property int minimumUsefulHeight: header.implicitHeight
                                               + swatchSeparator.implicitHeight
                                               + footer.implicitHeight + bottomPadding
    contentItem: ColumnLayout {
        visible: root.expanded
        spacing: 2

        Ui.VerticalSeparator {
            id: swatchSeparator
            visible: settings.autoSwatchEnabled
            leftPadding: 12
            topPadding: 0
            rightPadding: 12
            bottomPadding: 12

            Layout.fillWidth: true
        }
    }

    footer: ColumnLayout {
        visible: root.expanded
        spacing: 10

        Ui.VerticalSeparator {
            padding: 5
            topPadding: 5
            bottomPadding: 20

            Layout.fillWidth: true
        }
    }
}
