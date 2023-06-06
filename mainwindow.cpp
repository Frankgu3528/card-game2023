#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamechoose.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    GameChoose *gamech=new GameChoose(this);
    gamech->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    GameChoose *gamech=new GameChoose(this);
    gamech->show();
    this->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    GameChoose *gamech=new GameChoose(this);
    gamech->show();
    this->hide();
}
