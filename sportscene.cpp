#include "sportscene.h"
#include "ui_sportscene.h"
#include<QPainter>
#include<QPixmap>
#include<QColor>
#include<QDebug>
#include<QRgb>
#include<QFileInfo>
#include<QtCharts>

SportScene::SportScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SportScene)
{
    ui->setupUi(this);

    this->setWindowTitle("运动数据");
    this->setWindowIcon(QPixmap(":/images/appIcon.png"));

    ui->textEdit->setStyleSheet("background: transparent;");
    ui->textEdit_2->setStyleSheet("background: transparent;");
    ui->textEdit_4->setStyleSheet("background: transparent;");
    ui->textEdit_5->setStyleSheet("background: transparent;");
    ui->textEdit_7->setStyleSheet("background: transparent;");

    QTextCharFormat fmt;
    fmt.setForeground(QColor(qRgb(255,0,0)));
    fmt.setFontPointSize(12);
    QTextCursor cursor = ui->textEdit_standard->textCursor();
    cursor.mergeCharFormat(fmt);
    ui->textEdit_standard->setTextCursor(cursor);

    QTextCharFormat fmt2;
    fmt2.setForeground(QColor(qRgb(0,0,0)));
    fmt2.setFontPointSize(12);
    QTextCursor cursor2 = ui->textEdit_step->textCursor();
    cursor2.mergeCharFormat(fmt2);
    ui->textEdit_step->setTextCursor(cursor2);

    connect(ui->btn_standard,&QPushButton::clicked,[=](){
        this->step_standard=ui->textEdit_standard->toPlainText().toInt();
//        qDebug()<<this->step_standard;
    });

    connect(ui->btn_save,&QPushButton::clicked,[=](){
        QString date=ui->dateEdit->date().toString("yyyy/MM/dd");
        int step=ui->textEdit_step->toPlainText().toInt();
//        qDebug()<<this->step_standard<<date<<step;

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath + "/" + user_sport + "/sport.txt";
        QFile file(filepath);
        if(!file.open(QIODevice::Append | QIODevice::Text)){
            qDebug()<<"失败";
        }
//        else{
//            qDebug()<<"成功";
//        }
        QTextStream out(&file);
        out<<date<<"\n";
        out<<step<<"\n";
        file.close();
    });

    QChartView *currentChartView = nullptr;
    connect(ui->btn_step,&QPushButton::clicked,[=]()mutable{

        std::vector<int> m_step;
        std::vector<QString> m_date;

        QString currentFilePath = __FILE__;
        QFileInfo fileInfo(currentFilePath);
        QString DirPath = fileInfo.absolutePath() + "/txt";
        QString filepath=DirPath + "/" + user_sport + "/sport.txt";
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
                    int num=line.toInt();
                    m_step.push_back(num);
                }
            }
        }
        file_new.close();

        int n=m_step.size();

        QBarSet *set=new QBarSet("步数");
        set->setColor(qRgb(0,255,255));

        for(int i=0;i<n;i++){
            *set<<m_step[i];
        }

        QBarSeries *series = new QBarSeries();
        series->append(set);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("近期步数变化");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        for(int i=0;i<n;i++){
            categories<<m_date[i];
        }

        QLineSeries *lineSeries = new QLineSeries();
        lineSeries->setName("目标");
        lineSeries->append(0, this->step_standard);
        lineSeries->append(n - 1, this->step_standard);
        chart->addSeries(lineSeries);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        axisX->setLabelsAngle(-90);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0, 50000);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);


        lineSeries->attachAxis(axisY);

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

        ui->scrollArea_sport->setWidget(container);
    });


}

void SportScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/background_sport.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

SportScene::~SportScene()
{
    delete ui;
}
