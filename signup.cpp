#include "signup.h"
#include "ui_signup.h"
#include<QPainter>
#include<QPixmap>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<vector>
#include<QDir>
#include<QFileInfo>

SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);

    this->setWindowTitle("注册");
    this->setWindowIcon(QPixmap(":/images/appIcon.png"));

    connect(ui->btn_cancel,&QPushButton::clicked,[=](){
        this->close();
    });

    connect(ui->btn_sign,&QPushButton::clicked,[=](){
        QString username_num=ui->lineEdit_username->text();
        QString password_num1=ui->lineEdit_password->text();
        QString password_num2=ui->lineEdit_confirm->text();

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath+"/users.txt";
//        qDebug()<<filepath;
        QFile file(filepath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"失败"<<endl;
        }
        std::vector<QString> m_username;
        int count=0;
        QTextStream in(&file);
        while (!in.atEnd()) {
            count++;
            QString line = in.readLine();
            line.remove(QChar('\n'));
            if(count%2==1){
                m_username.push_back(line);
            }
        }

        file.close();

        int n=m_username.size();
        bool check=false;
        if(username_num=="users"){
            check=true;
        }
        else{
            for(int i=0;i<n;i++){
                if(username_num==m_username[i]){
                    check=true;
                    break;
                }
            }
        }

        if(check){
            QMessageBox::critical(this,"错误","该用户名已经存在");
        }
        else{
            if(isPasswordWeak(password_num1)){
                QMessageBox::critical(this,"错误","密码过于简单");
            }
            else{
                if(password_num1!=password_num2){
                    QMessageBox::critical(this,"错误","密码输入不一致");
                }
                else{
                    QFile file(filepath);
                    if(!file.open(QIODevice::Append | QIODevice::Text)){
                        qDebug()<<"失败"<<endl;
                    }
                    QTextStream out(&file);
                    out <<username_num<<"\n";
                    out <<password_num1<<"\n";
                    QMessageBox::information(this,"提示","注册成功");
                    file.close();

                    QDir dir;
                    if(!dir.exists(DirPath + "/" + username_num)){
                        dir.mkdir(DirPath + "/" + username_num);
                    }

                    QString basepath=DirPath + "/" + username_num;
                    QString filename_info = basepath + "/" + "info.txt";
                    QString filename_sport = basepath + "/" + "sport.txt";
                    QString filename_diet = basepath + "/" + "diet.txt";
                    QString filename_sleep = basepath + "/" + "sleep.txt";

                    QFile file1(filename_info);
                    if (!file1.open(QIODevice::WriteOnly | QIODevice::Text)) {
                        qDebug() << "信息文件创建失败" ;
                    }
                    file1.close();

                    QFile file2(filename_sport);
                    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
                        qDebug() << "步数文件创建失败" ;
                    }
                    file2.close();

                    QFile file3(filename_diet);
                    if (!file3.open(QIODevice::WriteOnly | QIODevice::Text)) {
                        qDebug() << "饮食文件创建失败" ;
                    }
                    file3.close();

                    QFile file4(filename_sleep);
                    if (!file4.open(QIODevice::WriteOnly | QIODevice::Text)) {
                        qDebug() << "睡眠文件创建失败" ;
                    }
                    file4.close();
                }
            }
        }
    });
}

void SignUp::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/backgroung_signup.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

bool isPasswordWeak(const QString& password) {

    if (password.length() < 6) {
        return true;
    }

    bool hasDigit = false;
    for (const QChar& c : password) {
        if (c.isDigit()) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        return true;
    }

    bool hasUpper = false;
    for (const QChar& c : password) {
        if (c.isUpper()) {
            hasUpper = true;
            break;
        }
    }
    if (!hasUpper) {
        return true;
    }

    bool hasLower = false;
    for (const QChar& c : password) {
        if (c.isLower()) {
            hasLower = true;
            break;
        }
    }
    if (!hasLower) {
        return true;
    }

    return false;
}

SignUp::~SignUp()
{
    delete ui;
}
