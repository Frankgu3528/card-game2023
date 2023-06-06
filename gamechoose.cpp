#include "gamechoose.h"
#include "ui_gamechoose.h"
#include "mainwindow.h"
#include "modechoose.h"

GameChoose::GameChoose(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameChoose)
{
    ui->setupUi(this);
}

GameChoose::~GameChoose()
{
    delete ui;
}

void GameChoose::on_pushButton_3_clicked()
{
    MainWindow *mw=dynamic_cast<MainWindow *>(this->parent());
    mw->show();
    this->close();
}

void GameChoose::on_pushButton_clicked()
{
    ModeChoose *mc=new ModeChoose(this);
    mc->show();
    this->hide();
}

void GameChoose::on_pushButton_2_clicked()
{
    ModeChoose *mc=new ModeChoose(this);
    mc->show();
    this->hide();
}
