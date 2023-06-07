#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamechoose.h"
#include <QDebug>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString localIP=getLocalIP();

    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}


QString MainWindow::getLocalIP()
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

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
// 创建游戏(服务+客户端)
{
    GameChoose *gamech=new GameChoose(this);
    gamech->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
//加入游戏(客户端)
{
//    GameChoose *gamech=new GameChoose(this);
//    gamech->show();
    qDebug() << "正在加入游戏" ;
    QUdpSocket udpClient;

    udpClient.bind(QHostAddress("10.196.193.214"), 9527); // 绑定到任意IP地址和随机端口号

    QByteArray datagram = "Hello, server!";

    udpClient.writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress("10.196.193.214"), 8888); // 向服务器发送数据包
    name = ui->lineEdit->text();
    QByteArray name1 = name.toUtf8();
    qDebug()<<name;
    udpClient.writeDatagram(name1.data(), name1.size(),
                             QHostAddress("10.196.193.214"), 8888);
        if (udpClient.waitForConnected()) {
            qDebug() << "Connected to server successfully!"; // 新添加的输出语句

        if (udpClient.hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(udpClient.pendingDatagramSize());
            QHostAddress senderAddress;
            quint16 senderPort;
            udpClient.readDatagram(datagram.data(), datagram.size(),
                                    &senderAddress, &senderPort);
            qDebug() << "Received datagram from" << senderAddress.toString()
                     << "on port" << senderPort;
            // 处理收到的数据
        }

    }
//    this->hide();

}
void MainWindow::on_pushButton_3_clicked()
{
    GameChoose *gamech=new GameChoose(this);
    gamech->show();
    this->hide();
}
