#include "sleepscene.h"
#include "ui_sleepscene.h"
#include<QPainter>
#include<QIcon>
#include<QPixmap>
#include<QDateTime>
#include<QDebug>
#include<QFileInfo>
#include<vector>
#include<QtCharts>

SleepScene::SleepScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SleepScene)
{
    ui->setupUi(this);

    this->setWindowTitle("睡眠数据");
    this->setWindowIcon(QPixmap(":/images/appIcon.png"));

    ui->textBrowser->setStyleSheet("background:transparent;");
    ui->textBrowser_2->setStyleSheet("background:transparent;");
    ui->textBrowser_3->setStyleSheet("background:transparent;");
    ui->textBrowser_4->setStyleSheet("background:transparent;");
    ui->textBrowser_5->setStyleSheet("background:transparent;");
    ui->textBrowser_6->setStyleSheet("background:transparent;");

    connect(ui->btn_save,&QPushButton::clicked,[=](){
        QDateTime time1=ui->dateTimeEdit->dateTime();
        QDateTime time2=ui->dateTimeEdit_2->dateTime();
        QString date=time2.toString("yyyy/MM/dd");
        int seconds = time1.secsTo(time2);
        int minutes=seconds/60;
        double hoursnum=(static_cast<double>(minutes)/60);
        QString time=QString::number(hoursnum,'f',2);
//        qDebug()<<date<<time;

        QString time_str;
        if(minutes<60){
            time_str=QString::number(minutes)+"分";
        }
        else{
            int count_hour=0;
            while(minutes-60>=0){
                count_hour++;
                minutes-=60;
            }
            time_str=QString::number(count_hour)+"时"+QString::number(minutes)+"分";
        }

        ui->textBrowser_6->setPlainText(time_str);
        QTextCursor cursor_1 = ui->textBrowser_6->textCursor();
        QTextCharFormat textFormat_1;
        textFormat_1.setFontPointSize(14);
        textFormat_1.setFontWeight(QFont::Bold);
        textFormat_1.setForeground(QColor(qRgb(255,255,0)));
        cursor_1.select(QTextCursor::Document);
        cursor_1.mergeCharFormat(textFormat_1);
        cursor_1.clearSelection();
        cursor_1.movePosition(QTextCursor::Start);
        ui->textBrowser_6->setCurrentCharFormat(textFormat_1);

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath + "/" + user_sleep + "/sleep.txt";
        QFile file(filepath);
        if(!file.open(QIODevice::Append | QIODevice::Text)){
            qDebug()<<"失败";
        }
//        else{
//            qDebug()<<"成功";
//        }
        QTextStream out(&file);
        out<<date<<"\n";
        out<<time<<"\n";
        file.close();
    });


    QChartView *currentChartView = nullptr;
    connect(ui->btn_sleep,&QPushButton::clicked,[=]()mutable{
        std::vector<double> m_sleep;
        std::vector<QString> m_date;

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath + "/" + user_sleep + "/sleep.txt";
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
                if(count%2==1){
                    m_date.push_back(line);
                }
                else{
                    double num=line.toDouble();
                    m_sleep.push_back(num);
                }
            }
        }
        file_new.close();

        int n=m_date.size();
        QBarSet *set=new QBarSet("睡眠时长");
        set->setColor(qRgb(255,0,0));
        for(int i=0;i<n;i++){
            *set<<m_sleep[i];
        }

        QBarSeries *series = new QBarSeries();
        series->append(set);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("近期睡眠情况");
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
        axisY->setRange(0, 24);
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

        ui->scrollArea_sleep->setWidget(container);
    });

}

void SleepScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/background_sleep.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

SleepScene::~SleepScene()
{
    delete ui;
}
