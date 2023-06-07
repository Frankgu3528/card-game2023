#include "waitroom.h"
#include "ui_waitroom.h"
#include "numchoose.h"
#include "ui_numchoose.h"
#include "modechoose.h"
#include <QDebug>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork>

waitroom::waitroom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::waitroom)
{
    ui->setupUi(this);
    qDebug() << "fsd ";
    /*QUdpSocket udpServer;
      udpServer.bind(QHostAddress("10.196.193.214"), 8888); // 监听任意IP地址和端口号8888

      QByteArray datagram;
      QHostAddress senderAddress;
      quint16 senderPort;
      // 设置超时时间为5秒
      qDebug() <<"server start" ;

      int ifSomeOneJoined = 0;
      bool isBroadcasting = true;
      while (isBroadcasting) {
      while (udpServer.hasPendingDatagrams()) {
          datagram.resize(udpServer.pendingDatagramSize());
          udpServer.readDatagram(datagram.data(), datagram.size(),
                                 &senderAddress, &senderPort);
          qDebug() << "Received datagram from" << senderAddress.toString()
                   << "on port" << senderPort;
          // 处理收到的数据
         qDebug() << "Received datagram: " << datagram; // 新添加的输出语句
         ifSomeOneJoined +=1;
         isBroadcasting = false;
         qDebug()<<"Someone entered!";
        }
      }
      if(ifSomeOneJoined==0) {qDebug() << "NoOne Join me!";}*/
}

QString waitroom::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QString   localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();//

    if (!addList.isEmpty())
    for (int i=0;i<addList.count();i++)
    {
        QHostAddress aHost=addList.at(i);
        if (QAbstractSocket::IPv4Protocol==aHost.protocol())
        {
            localIP=aHost.toString();
            break;
        }
    }
    return localIP;
}
void waitroom::on_pushButton_7_clicked(){

qDebug() << "hahah";
UdpServer server;
 QThread thread;

 server.moveToThread(&thread);
 QObject::connect(&thread, &QThread::started, &server, &UdpServer::start);
 thread.start();
}


waitroom::~waitroom()
{
    delete ui;
}
