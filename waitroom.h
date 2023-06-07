#ifndef WAITROOM_H
#define WAITROOM_H
#include <QThread>
#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QDebug>

namespace Ui {
class waitroom;
}
class UdpServer : public QObject
{
    Q_OBJECT

public:
    UdpServer(QObject *parent = nullptr) : QObject(parent) {}

public slots:
    void start()
    {
        QUdpSocket udpServer;
        if (!udpServer.bind(QHostAddress::Any, 1234)) {
            qDebug() << "Failed to bind to port 1234";
            return;
        }

        bool isBroadcasting = true;
        while (isBroadcasting) {
            QByteArray datagram("Hello from UDP server");
            if (udpServer.writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 5678) == -1) {
                qDebug() << "Failed to send broadcast datagram";
            } else {
                qDebug() << "Broadcast datagram sent";
            }

            // Wait for up to 5 seconds for incoming datagrams
            if (udpServer.waitForReadyRead(5000)) {
                while (udpServer.hasPendingDatagrams()) {
                    QByteArray buffer;
                    buffer.resize(udpServer.pendingDatagramSize());
                    QHostAddress sender;
                    quint16 senderPort;

                    udpServer.readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
                    qDebug() << "Received datagram from" << sender.toString() << ":" << senderPort;
                    qDebug() << "Data:" << buffer;
                    isBroadcasting = false;
                }
            } else {
                qDebug() << "No datagrams received within 5 seconds";
            }
        }
    }
};
class waitroom : public QMainWindow
{
    Q_OBJECT


public:
    explicit waitroom(QWidget *parent = nullptr);
    ~waitroom();
private slots:
    void on_pushButton_7_clicked();

private:
    Ui::waitroom *ui;
    QString getLocalIP();
};

#endif // WAITROOM_H
