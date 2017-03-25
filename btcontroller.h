#ifndef BTCONTROLLER_H
#define BTCONTROLLER_H

#include <QObject>
#include <qbluetoothglobal.h>
#include <QBluetoothLocalDevice>
#include <QBluetoothServiceDiscoveryAgent>
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceDiscoveryAgent)
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceInfo)

QT_USE_NAMESPACE
class BtController : public QObject
{
    Q_OBJECT
public:
        BtController();
        ~BtController();
public slots:
        void addDevice(const QBluetoothDeviceInfo&);
private slots:
        void scanFinished();
        void hostModeStateChanged(QBluetoothLocalDevice::HostMode);
        void pairingDone(const QBluetoothAddress&, QBluetoothLocalDevice::Pairing);

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QList<QString> devices;
};

#endif // BTCONTROLLER_H
