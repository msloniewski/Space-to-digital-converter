import QtQuick 2.6
import QtQuick.Window 2.2
import QtCharts 2.0

Window {

    height: 400
    width: 400
    visible: true

    Rectangle
    {
        objectName: "dass"
    }

    ChartView {

        width: 400
        height: 300
        theme: ChartView.ChartThemeBrownSand
        antialiasing: true
        LineSeries {
               name: "asd"
               objectName:"asd"
               XYPoint { x: 0; y: 0.0 }
               XYPoint { x: 1.1; y: 3.2 }
               XYPoint { x: 1.9; y: 2.4 }
               XYPoint { x: 2.1; y: 2.1 }
               XYPoint { x: 2.9; y: 2.6 }
               XYPoint { x: 3.4; y: 2.3 }
               XYPoint { x: 4.1; y: 3.1 }
           }
    }


}
