#include "modechoose.h"
#include "ui_modechoose.h"
#include "gamechoose.h"
#include "numchoose.h"
#include <QDebug>
#include <QtNetwork/QUdpSocket>
ModeChoose::ModeChoose(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModeChoose)
{
    ui->setupUi(this);
}

ModeChoose::~ModeChoose()
{
    delete ui;
}

void ModeChoose::on_pushButton_3_clicked()
{
    GameChoose *gc=dynamic_cast<GameChoose *>(this->parent());
    gc->show();
    this->close();
}

void ModeChoose::on_pushButton_2_clicked()
{
    // 客户选择联机游戏
    // 这时候作为游戏的创建者要开始udp广播(服务器)
    QUdpSocket udpServer;
      udpServer.bind(QHostAddress("10.196.193.214"), 8888); // 监听任意IP地址和端口号8888

      QByteArray datagram;
      QHostAddress senderAddress;
      quint16 senderPort;
      // 设置超时时间为5秒
      qDebug() <<"server start" ;
      udpServer.waitForReadyRead(25000);
      int ifSomeOneJoined = 0;
      while (udpServer.hasPendingDatagrams()) {
          datagram.resize(udpServer.pendingDatagramSize());
          udpServer.readDatagram(datagram.data(), datagram.size(),
                                 &senderAddress, &senderPort);
          qDebug() << "Received datagram from" << senderAddress.toString()
                   << "on port" << senderPort;
          // 处理收到的数据
         qDebug() << "Received datagram: " << datagram; // 新添加的输出语句
         ifSomeOneJoined +=1;
         qDebug()<<"Someone entered!";
      }
      if (ifSomeOneJoined==0) {qDebug() << "NoOne Join me!";}

}
