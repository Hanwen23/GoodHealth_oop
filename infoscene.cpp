#include "infoscene.h"
#include "ui_infoscene.h"
#include<QPixmap>
#include<QIcon>
#include<QPainter>
#include<QFile>
#include<QDebug>
#include<QDate>
#include<QSlider>
#include<QSpinBox>
#include<QTextStream>
#include<cmath>
#include<QRgb>
#include<QFileInfo>
#include<QScrollArea>
#include<vector>
#include<QtCharts>

InfoScene::InfoScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoScene)
{
    ui->setupUi(this);

    this->setWindowTitle("身体基本信息");
    this->setWindowIcon(QPixmap(":/images/appIcon.png"));

    ui->textBrowser->setStyleSheet("background: transparent;");
    ui->textBrowser_2->setStyleSheet("background: transparent;");

    ui->textBrowser_info1->setStyleSheet("background: transparent;");
    ui->textBrowser_info2->setStyleSheet("background: transparent;");
    ui->textBrowser_info3->setStyleSheet("background: transparent;");
    ui->textBrowser_info4->setStyleSheet("background: transparent;");

    ui->scrollArea_weight->setStyleSheet("QScrollArea { background: transparent; }");

    ui->textBrowser_BMI->setStyleSheet("background: transparent;");

    ui->spinBox_height->setRange(0,250);
    ui->horizontalSlider_height->setRange(0,250);
    ui->spinBox_weight->setRange(0,150);
    ui->horizontalSlider_weight->setRange(0,150);

    void(QSpinBox::*signal_1)(int)=&QSpinBox::valueChanged;//函数指针，参数int的valuechanged函数
    connect(ui->spinBox_height,signal_1,ui->horizontalSlider_height,&QSlider::setValue);
    connect(ui->horizontalSlider_height,&QSlider::valueChanged,ui->spinBox_height,&QSpinBox::setValue);

    void(QSpinBox::*signal_2)(int)=&QSpinBox::valueChanged;//函数指针，参数int的valuechanged函数
    connect(ui->spinBox_weight,signal_2,ui->horizontalSlider_weight,&QSlider::setValue);
    connect(ui->horizontalSlider_weight,&QSlider::valueChanged,ui->spinBox_weight,&QSpinBox::setValue);

    connect(ui->btn_save,&QPushButton::clicked,[=](){

//        qDebug()<<this->user_info;

        QString date=ui->calendar->selectedDate().toString("yyyy/MM/dd");
        int user_height=ui->spinBox_height->value();
        int user_weight=ui->spinBox_weight->value();
        double BMI = static_cast<double>(user_weight) / (static_cast<double>(user_height) / 100) / (static_cast<double>(user_height) / 100);


//        qDebug()<<user_height<<user_weight<<BMI;

        QString numberStr = QString::number(BMI,'f',1);

        if(BMI<18.5){
            ui->textBrowser_info2->setPlainText(numberStr);
            QTextCursor cursor_1 = ui->textBrowser_info2->textCursor();
            QTextCharFormat textFormat_1;
            textFormat_1.setFontPointSize(14);
            textFormat_1.setForeground(QColor(qRgb(0,0,255)));
            cursor_1.select(QTextCursor::Document);
            cursor_1.mergeCharFormat(textFormat_1);
            cursor_1.clearSelection();
            cursor_1.movePosition(QTextCursor::Start);
            ui->textBrowser_info2->setCurrentCharFormat(textFormat_1);
            ui->textBrowser_info4->setPlainText("体重过低");
            QTextCursor cursor_2 = ui->textBrowser_info4->textCursor();
            QTextCharFormat textFormat_2;
            textFormat_2.setFontPointSize(14);
            textFormat_2.setForeground(QColor(qRgb(0,0,255)));
            cursor_2.select(QTextCursor::Document);
            cursor_2.mergeCharFormat(textFormat_2);
            cursor_2.clearSelection();
            cursor_2.movePosition(QTextCursor::Start);
            ui->textBrowser_info4->setCurrentCharFormat(textFormat_2);
        }
        else if(BMI>=18.5&&BMI<=23.9){
            ui->textBrowser_info2->setPlainText(numberStr);
            QTextCursor cursor_1 = ui->textBrowser_info2->textCursor();
            QTextCharFormat textFormat_1;
            textFormat_1.setFontPointSize(14);
            textFormat_1.setForeground(QColor(qRgb(0,170,0)));
            cursor_1.select(QTextCursor::Document);
            cursor_1.mergeCharFormat(textFormat_1);
            cursor_1.clearSelection();
            cursor_1.movePosition(QTextCursor::Start);
            ui->textBrowser_info2->setCurrentCharFormat(textFormat_1);
            ui->textBrowser_info4->setPlainText("体重正常");
            QTextCursor cursor_2 = ui->textBrowser_info4->textCursor();
            QTextCharFormat textFormat_2;
            textFormat_2.setFontPointSize(14);
            textFormat_2.setForeground(QColor(qRgb(0,170,0)));
            cursor_2.select(QTextCursor::Document);
            cursor_2.mergeCharFormat(textFormat_2);
            cursor_2.clearSelection();
            cursor_2.movePosition(QTextCursor::Start);
            ui->textBrowser_info4->setCurrentCharFormat(textFormat_2);
        }
        else if(BMI>23.9&&BMI<=27.9){
            ui->textBrowser_info2->setPlainText(numberStr);
            QTextCursor cursor_1 = ui->textBrowser_info2->textCursor();
            QTextCharFormat textFormat_1;
            textFormat_1.setFontPointSize(14);
            textFormat_1.setForeground(QColor(qRgb(170,85,0)));
            cursor_1.select(QTextCursor::Document);
            cursor_1.mergeCharFormat(textFormat_1);
            cursor_1.clearSelection();
            cursor_1.movePosition(QTextCursor::Start);
            ui->textBrowser_info2->setCurrentCharFormat(textFormat_1);
            ui->textBrowser_info4->setPlainText("超重");
            QTextCursor cursor_2 = ui->textBrowser_info4->textCursor();
            QTextCharFormat textFormat_2;
            textFormat_2.setFontPointSize(14);
            textFormat_2.setForeground(QColor(qRgb(170,85,0)));
            cursor_2.select(QTextCursor::Document);
            cursor_2.mergeCharFormat(textFormat_2);
            cursor_2.clearSelection();
            cursor_2.movePosition(QTextCursor::Start);
            ui->textBrowser_info4->setCurrentCharFormat(textFormat_2);
        }
        else{
            ui->textBrowser_info2->setPlainText(numberStr);
            QTextCursor cursor_1 = ui->textBrowser_info2->textCursor();
            QTextCharFormat textFormat_1;
            textFormat_1.setFontPointSize(14);
            textFormat_1.setForeground(QColor(qRgb(255,0,0)));
            cursor_1.select(QTextCursor::Document);
            cursor_1.mergeCharFormat(textFormat_1);
            cursor_1.clearSelection();
            cursor_1.movePosition(QTextCursor::Start);
            ui->textBrowser_info2->setCurrentCharFormat(textFormat_1);
            ui->textBrowser_info4->setPlainText("肥胖");
            QTextCursor cursor_2 = ui->textBrowser_info4->textCursor();
            QTextCharFormat textFormat_2;
            textFormat_2.setFontPointSize(14);
            textFormat_2.setForeground(QColor(qRgb(255,0,0)));
            cursor_2.select(QTextCursor::Document);
            cursor_2.mergeCharFormat(textFormat_2);
            cursor_2.clearSelection();
            cursor_2.movePosition(QTextCursor::Start);
            ui->textBrowser_info4->setCurrentCharFormat(textFormat_2);
        }

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath + "/" + user_info + "/info.txt";
        QFile file(filepath);
        if(!file.open(QIODevice::Append | QIODevice::Text)){
            qDebug()<<"失败";
        }
//        else{
//            qDebug()<<"成功";
//        }
        QTextStream out(&file);
        out<<date<<"\n";
        out<<user_height<<"\n";
        out<<user_weight<<"\n";
        out<<BMI<<"\n";
        file.close();
    });

    QChartView *currentChartView = nullptr;
    connect(ui->btn_weight,&QPushButton::clicked,[=]()mutable{

        std::vector<int> m_weight;
        std::vector<QString> m_date;

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath + "/" + user_info + "/info.txt";
        QFile file_new(filepath);
        if(!file_new.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"失败";
        }
        else{
            int count=0;
            QTextStream in(&file_new);
            while(!in.atEnd()){
                count++;
                QString line=in.readLine();
                if(count%4==3){
                    int num=line.toInt();
                    m_weight.push_back(num);
                }
                else if(count%4==1){
                    m_date.push_back(line);
                }
            }
        }
        int n=m_weight.size();
//        for(int i=0;i<n;i++){
//            qDebug()<<m_weight[i]<<m_date[i];
//        }
        file_new.close();

        QBarSet *set=new QBarSet("体重");

        for(int i=0;i<n;i++){
            *set<<m_weight[i];
        }

        QBarSeries *series = new QBarSeries();
        series->append(set);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("近期体重变化规律");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        for(int i=0;i<n;i++){
            categories<<m_date[i];
        }

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        axisX->setLabelsAngle(-90);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0, 150);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        if (currentChartView) {
            delete currentChartView->parentWidget(); // 删除包含图表视图的布局和小部件
        }

        // 保存当前的图表视图
        currentChartView = chartView;

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);

        QWidget *container = new QWidget();
        container->setLayout(layout);

        ui->scrollArea_weight->setWidget(container);
    });

    QChartView *currentChartView2 = nullptr;
    connect(ui->btn_height,&QPushButton::clicked,[=]()mutable{

        std::vector<int> m_height;
        std::vector<QString> m_date;

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath + "/" + user_info + "/info.txt";
        QFile file_new(filepath);
        if(!file_new.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"失败";
        }
        else{
            int count=0;
            QTextStream in(&file_new);
            while(!in.atEnd()){
                count++;
                QString line=in.readLine();
                if(count%4==2){
                    int num=line.toInt();
                    m_height.push_back(num);
                }
                else if(count%4==1){
                    m_date.push_back(line);
                }
            }
        }
        int n=m_height.size();
//        for(int i=0;i<n;i++){
//            qDebug()<<m_weight[i]<<m_date[i];
//        }
        file_new.close();

        QBarSet *set=new QBarSet("身高");
        set->setColor(qRgb(255,85,0));

        for(int i=0;i<n;i++){
            *set<<m_height[i];
        }

        QBarSeries *series = new QBarSeries();
        series->append(set);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("近期身高变化规律");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        for(int i=0;i<n;i++){
            categories<<m_date[i];
        }

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        axisX->setLabelsAngle(-90);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0, 250);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        if (currentChartView2) {
            delete currentChartView2->parentWidget(); // 删除包含图表视图的布局和小部件
        }

        // 保存当前的图表视图
        currentChartView2 = chartView;

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);

        QWidget *container = new QWidget();
        container->setLayout(layout);

        ui->scrollArea_height->setWidget(container);
    });
}

void InfoScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/background_info.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

InfoScene::~InfoScene()
{
    delete ui;
}
