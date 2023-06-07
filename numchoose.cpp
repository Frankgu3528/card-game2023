#include "numchoose.h"
#include "ui_numchoose.h"
#include "modechoose.h"
#include "waitroom.h"
#include <QDebug>
#include <QtNetwork/QUdpSocket>
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
void NumChoose::on_pushButton_6_clicked(){


    waitroom *wt=new waitroom(this);
    wt->show();
//    this->close();

}
void NumChoose::on_pushButton_3_clicked()
{
    // 返回键
    ModeChoose *mc=dynamic_cast<ModeChoose *>(this->parent());
    mc->show();
    this->close();


}
