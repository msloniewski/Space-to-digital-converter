#ifndef BTCONTROLLER_H
#define BTCONTROLLER_H

#include <QObject>
#include <qbluetoothglobal.h>
#include <QBluetoothLocalDevice>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QLineSeries>
#include <QChart>
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceDiscoveryAgent)
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceInfo)

QT_USE_NAMESPACE
class BtController : public QObject
{
    Q_OBJECT
public:
        BtController();
        ~BtController();
        //void toggleOnOffLocalDev();
        void addSeries(QtCharts::QLineSeries *a_series);
        void addChart(QtCharts::QChart *a_chart);
public slots:
        //void addDevice(const QBluetoothDeviceInfo&);
        void slotRead();
private slots:
        //void scanFinished();
        //void hostModeStateChanged(QBluetoothLocalDevice::HostMode);
        //void pairingDone(const QBluetoothAddress&, QBluetoothLocalDevice::Pairing);
private:
    //QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    //QList<QString> devices;
    //bool LocDevOnOff = false;
    QBluetoothSocket* socket;
    QBluetoothLocalDevice *localDevice;
    QtCharts::QChart *chart;
    QtCharts::QLineSeries *series;
    int iloscdanych=0;

};

#endif // BTCONTROLLER_H
