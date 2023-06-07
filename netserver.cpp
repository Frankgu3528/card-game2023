#include "netserver.h"

netServer::netServer()
{

}


void netServer::readPendingDatagrams()
{
    while (receiver->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(), datagram.size());
    }
}
