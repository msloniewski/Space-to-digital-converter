#include "btcontroller.h"

#include <QBluetoothAddress>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothServiceInfo>
#include <QBluetoothLocalDevice>
#include <QBluetoothUuid>
#include <QBluetoothDeviceDiscoveryAgent>

#include <QDebug>
static const QLatin1String serviceUuid("e8e10f95-1a70-4b27-9ccf-02010264e9c8");

BtController::BtController(): localDevice(new QBluetoothLocalDevice)
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();

    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(addDevice(QBluetoothDeviceInfo)));
    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(scanFinished()));

    connect(localDevice, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)),
            this, SLOT(hostModeStateChanged(QBluetoothLocalDevice::HostMode)));

    hostModeStateChanged(localDevice->hostMode());

    connect(localDevice, SIGNAL(pairingFinished(QBluetoothAddress,QBluetoothLocalDevice::Pairing))
        , this, SLOT(pairingDone(QBluetoothAddress,QBluetoothLocalDevice::Pairing)));



    //TUTAJ LECIMY CHUJOWO NA SEKWENCJE
    discoveryAgent->start();



}

BtController::~BtController()
{
}

void BtController::scanFinished()
{
    //NIC?
}

void BtController::pairingDone(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing)
{
    if (pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired ) {
        qDebug()<<address.toString()<<"paired";
    } else {
        qDebug()<<address.toString()<<"paired failed";
    }
}

void BtController::addDevice(const QBluetoothDeviceInfo &info)
{
    QString label = QString("%1 %2").arg(info.address().toString()).arg(info.name());
    if ( !devices.contains( label ) )
    {
        devices.append( label );
        qDebug()<< "Added device: " << label;
        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());
        if (pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired )
            qDebug()<<"And it's paired";
        else
            qDebug()<<"And it's not paired";
    }

}
void BtController::hostModeStateChanged(QBluetoothLocalDevice::HostMode mode)
{
    if (mode != QBluetoothLocalDevice::HostPoweredOff)
        qDebug()<<"HostPoweredOff";
    else
        qDebug()<<"HostPoweredOn";

    if (mode == QBluetoothLocalDevice::HostDiscoverable)
        qDebug()<<"HostDiscoverable";
    else
        qDebug()<<"HostUndiscoverable";

    /*bool on = !(mode == QBluetoothLocalDevice::HostPoweredOff);

    ui->scan->setEnabled(on);
    ui->discoverable->setEnabled(on);*/
}