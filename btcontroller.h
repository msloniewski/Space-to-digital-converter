#ifndef BTCONTROLLER_H
#define BTCONTROLLER_H

#include <QObject>
#include <qbluetoothglobal.h>
#include <QBluetoothLocalDevice>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothSocket>
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceDiscoveryAgent)
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceInfo)

QT_USE_NAMESPACE
class BtController : public QObject
{
    Q_OBJECT
public:
        BtController();
        ~BtController();
        void toggleOnOffLocalDev();
        QBluetoothSocket* socket;
public slots:
        void addDevice(const QBluetoothDeviceInfo&);
        void slotRead();
private slots:
        void scanFinished();
        void hostModeStateChanged(QBluetoothLocalDevice::HostMode);
        void pairingDone(const QBluetoothAddress&, QBluetoothLocalDevice::Pairing);
private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QList<QString> devices;
    bool LocDevOnOff = false;
};

#endif // BTCONTROLLER_H
