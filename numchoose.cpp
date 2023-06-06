#include "numchoose.h"
#include "ui_numchoose.h"
#include "modechoose.h"

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

void NumChoose::on_pushButton_3_clicked()
{
    ModeChoose *mc=dynamic_cast<ModeChoose *>(this->parent());
    mc->show();
    this->close();
}
