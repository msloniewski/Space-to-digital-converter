#include <QApplication>
#include <QQmlApplicationEngine>


#include "btcontroller.h"
#include<QBluetoothDeviceDiscoveryAgent>
#include <QThread>
#include <QBluetoothSocket>
#include <QLineSeries>
#include <QMainWindow>
#include <QChart>
#include <QChartView>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/mainWindow.qml")));
    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();



       QtCharts::QChart *chart = new QtCharts::QChart();
       chart->legend()->hide();
       chart->addSeries(series);
       chart->createDefaultAxes();
       chart->setTitle("Simple line chart example");

       QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       QMainWindow window;
       window.setCentralWidget(chartView);
       window.resize(400, 300);
       window.show();

    //QBluetoothLocalDevice localDevice;
    //QString localDeviceName;
   BtController ctrl;
   ctrl.addChart(chart);
   ctrl.addSeries(series);

   //ctrl.slotRead();
    /*if (localDevice.isValid()) {

        // Turn Bluetooth on
        localDevice.powerOn();

        // Read local device name
        localDeviceName = localDevice.name();

        // Make it visible to others
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // Get connected devices
        QList<QBluetoothAddress> remotes;
        remotes = localDevice.connectedDevices();

        ctrl.socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
        qDebug() << "Create socket";
        static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805f9b34fb");
        QBluetoothUuid uuid (serviceUuid);
        ctrl.socket->connectToService( QBluetoothAddress("98:D3:31:80:98:49"), uuid );
        QObject::connect( ctrl.socket, SIGNAL(readyRead()), &ctrl, SLOT(slotRead() ) );
        qDebug() << "ConnectToService done";

    }*/

/*
    DeviceDiscoveryDialog d;
    QObject::connect(&d, SIGNAL(accepted()), &app, SLOT(quit()));
    d.show();
*/
    return app.exec();
}
