#include "numchoose.h"
#include "ui_numchoose.h"
#include "modechoose.h"
#include "waitroom.h"
#include <QDebug>
#include <QtNetwork>
#include <QtNetwork/QUdpSocket>
int playernum = 0; // 全局变量用于获取游戏人数
NumChoose::NumChoose(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NumChoose)
{
    ui->setupUi(this);
}

NumChoose::~NumChoose()
{
    delete ui;
}
class NetworkThread : public QThread
{
public:
    void run() override {
        QUdpSocket udpServer;
        QString localIP=getLocalIP();
          udpServer.bind(QHostAddress(localIP), 8888); // 监听任意IP地址和端口号8888
        qDebug() << "server IP:" << localIP ;
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
             qDebug() << "Received datagram: " << datagram;
             ifSomeOneJoined +=1;

           // 如果人数到了上一页指定的人数，那么停止udp广播
           if(ifSomeOneJoined==(playernum-1)) isBroadcasting = false;
             qDebug()<<"Someone entered!";
            }
          }

          if(ifSomeOneJoined==0) {qDebug() << "NoOne Join me!";}
    }
    QString getLocalIP()
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
};
void NumChoose::on_pushButton_clicked(){playernum = 1;}
void NumChoose::on_pushButton_2_clicked(){playernum = 2;}
void NumChoose::on_pushButton_4_clicked(){playernum = 3;}
void NumChoose::on_pushButton_5_clicked(){playernum = 4;}

void NumChoose::on_pushButton_6_clicked(){

    qDebug() << "fsd "<<playernum;
    waitroom *wt=new waitroom(this);
    wt->show();

    // 用户点了开始键后，房主作为服务器开始udp广播
    // 这里用多线程的写法，开了一个新线程
    // 因为持续广播会阻塞主线程
    NetworkThread *thread = new NetworkThread();
    thread->start();


}
void NumChoose::on_pushButton_3_clicked()
{
    // 返回键
    ModeChoose *mc=dynamic_cast<ModeChoose *>(this->parent());
    mc->show();
    this->close();


}
