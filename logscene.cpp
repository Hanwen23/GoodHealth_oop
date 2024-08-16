#include "logscene.h"
#include "ui_logscene.h"
#include"signup.h"
#include"mainwindow.h"
#include<QIcon>
#include<QPixmap>
#include<QPainter>
#include<vector>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QFileInfo>

LogScene::LogScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogScene)
{
    ui->setupUi(this);

    this->setWindowIcon(QPixmap(":/images/appIcon.png"));

    QPixmap pixlog(":/images/appIcon.png");
    ui->label_pixlog->setFixedSize(this->width()/6,this->height()/4);
    ui->label_pixlog->setPixmap(pixlog);
    ui->label_pixlog->setScaledContents(true);

    SignUp *signup_widget=new SignUp;
    connect(ui->btn_sign,&QPushButton::clicked,[=](){
        signup_widget->show();
    });

    connect(ui->btn_log,&QPushButton::clicked,[=](){
        QString num_username=ui->lineEdit_username->text();
        QString num_password=ui->lineEdit_password->text();

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath+"/users.txt";
        QFile file(filepath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"失败"<<endl;
        }
        std::vector<QString> m_username,m_password;
        int count=0;
        QTextStream in(&file);
        while (!in.atEnd()) {
            count++;
            QString line = in.readLine();
            line.remove(QChar('\n'));
            if(count%2==1){
                m_username.push_back(line);
            }
            else{
                m_password.push_back(line);
            }
        }

        MainWindow *new_mainwindow=new MainWindow;
        int n=m_username.size();
        bool check=false;
        for(int i=0;i<n;i++){
            if(num_username==m_username[i]){
                if(num_password==m_password[i]){
                    new_mainwindow->show();
                    new_mainwindow->user=num_username;
                }
                else{
                    QMessageBox::critical(this,"错误","密码错误");
                }
                check=true;
                break;
            }
        }
        if(!check){
            QMessageBox::critical(this,"错误","用户不存在");
        }

        file.close();
    });
}

void LogScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/background_logScene.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

LogScene::~LogScene()
{
    delete ui;
}

