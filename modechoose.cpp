#include "modechoose.h"
#include "ui_modechoose.h"
#include "gamechoose.h"
#include "numchoose.h"

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
    NumChoose *nc=new NumChoose(this);
    nc->show();
    this->hide();
}
