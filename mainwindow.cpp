#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"infoscene.h"
#include"logscene.h"
#include"sportscene.h"
#include"dietscene.h"
#include"sleepscene.h"
#include<QPainter>
#include<QPixmap>
#include<QDebug>
#include<QFile>
#include<QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QPixmap(":/images/appIcon.png"));

    this->setWindowTitle("GoodHealth");

    InfoScene *info=new InfoScene;
    connect(ui->btn_info,&QPushButton::clicked,[=](){
        info->user_info=this->user;
        info->show();
    });

    SportScene *sport=new SportScene;
    connect(ui->btn_sport,&QPushButton::clicked,[=](){
        sport->user_sport=this->user;
        sport->show();
    });

    DietScene *diet=new DietScene;
    connect(ui->btn_diet,&QPushButton::clicked,[=](){
        diet->user_diet=this->user;
        diet->show();
    });

    SleepScene *sleep=new SleepScene;
    connect(ui->btn_sleep,&QPushButton::clicked,[=](){
        sleep->user_sleep=this->user;
        sleep->show();
    });
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/background_mainwindow.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
