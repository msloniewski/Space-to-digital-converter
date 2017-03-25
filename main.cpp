#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "device.h"
#include "btcontroller.h"
#include<QBluetoothDeviceDiscoveryAgent>
#include <QThread>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    while (1)
    {
        BtController a;
        QThread::sleep( 1 );
    }

    DeviceDiscoveryDialog d;
    QObject::connect(&d, SIGNAL(accepted()), &app, SLOT(quit()));
    d.show();

    return app.exec();
}
