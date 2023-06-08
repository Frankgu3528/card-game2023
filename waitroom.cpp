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
}


void waitroom::on_pushButton_7_clicked(){
//
qDebug() << "hahah";


}


waitroom::~waitroom()
{
    delete ui;
}
