#include "dietscene.h"
#include "ui_dietscene.h"
#include<QPainter>
#include<QIcon>
#include<QPixmap>
#include<QFileInfo>
#include<QDebug>
#include<QtCharts>

DietScene::DietScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DietScene)
{
    ui->setupUi(this);

    this->setWindowTitle("饮食健康");
    this->setWindowIcon(QPixmap(":/images/appIcon.png"));

     ui->textEdit->setStyleSheet("background:transparent;");
     ui->textEdit_main->setStyleSheet("background:transparent;");
     ui->textEdit_vegetable->setStyleSheet("background:transparent;");
     ui->textEdit_meat->setStyleSheet("background:transparent;");
     ui->textBrowser->setStyleSheet("background:transparent;");
     ui->textBrowser_2->setStyleSheet("background:transparent;");


     //主食类
     ui->label_rice->setFixedSize(this->width()/4,this->height()/5);
     ui->label_rice->setPixmap(QPixmap(":/images/rice.png"));
     ui->label_rice->setScaledContents(true);
     ui->label_noodles->setFixedSize(this->width()/4,this->height()/5);
     ui->label_noodles->setPixmap(QPixmap(":/images/noodles.png"));
     ui->label_noodles->setScaledContents(true);
     ui->label_porridge->setFixedSize(this->width()/4,this->height()/5);
     ui->label_porridge->setPixmap(QPixmap(":/images/porridge.png"));
     ui->label_porridge->setScaledContents(true);
     ui->label_mantou->setFixedSize(this->width()/4,this->height()/5);
     ui->label_mantou->setPixmap(QPixmap(":/images/mantou.png"));
     ui->label_mantou->setScaledContents(true);
     ui->label_bread->setFixedSize(this->width()/4,this->height()/5);
     ui->label_bread->setPixmap(QPixmap(":/images/bread.png"));
     ui->label_bread->setScaledContents(true);
     ui->label_youtiao->setFixedSize(this->width()/4,this->height()/5);
     ui->label_youtiao->setPixmap(QPixmap(":/images/youtiao.png"));
     ui->label_youtiao->setScaledContents(true);
     ui->label_hamburger->setFixedSize(this->width()/4,this->height()/5);
     ui->label_hamburger->setPixmap(QPixmap(":/images/hamburger.png"));
     ui->label_hamburger->setScaledContents(true);
     ui->label_pizza->setFixedSize(this->width()/4,this->height()/5);
     ui->label_pizza->setPixmap(QPixmap(":/images/pizza.png"));
     ui->label_pizza->setScaledContents(true);
     ui->label_popcorn->setFixedSize(this->width()/4,this->height()/5);
     ui->label_popcorn->setPixmap(QPixmap(":/images/popcorn.png"));
     ui->label_popcorn->setScaledContents(true);

     //蔬菜水果
     ui->label_shengcai->setFixedSize(this->width()/4,this->height()/5);
     ui->label_shengcai->setPixmap(QPixmap(":/images/shengcai.png"));
     ui->label_shengcai->setScaledContents(true);
     ui->label_celery->setFixedSize(this->width()/4,this->height()/5);
     ui->label_celery->setPixmap(QPixmap(":/images/celery.png"));
     ui->label_celery->setScaledContents(true);
     ui->label_corn->setFixedSize(this->width()/4,this->height()/5);
     ui->label_corn->setPixmap(QPixmap(":/images/corn.png"));
     ui->label_corn->setScaledContents(true);
     ui->label_bocai->setFixedSize(this->width()/4,this->height()/5);
     ui->label_bocai->setPixmap(QPixmap(":/images/bocai.png"));
     ui->label_bocai->setScaledContents(true);
     ui->label_tomato->setFixedSize(this->width()/4,this->height()/5);
     ui->label_tomato->setPixmap(QPixmap(":/images/tomato.png"));
     ui->label_tomato->setScaledContents(true);
     ui->label_carrot->setFixedSize(this->width()/4,this->height()/5);
     ui->label_carrot->setPixmap(QPixmap(":/images/carrot.png"));
     ui->label_carrot->setScaledContents(true);
     ui->label_banana->setFixedSize(this->width()/4,this->height()/5);
     ui->label_banana->setPixmap(QPixmap(":/images/banana.png"));
     ui->label_banana->setScaledContents(true);
     ui->label_apple->setFixedSize(this->width()/4,this->height()/5);
     ui->label_apple->setPixmap(QPixmap(":/images/apple.png"));
     ui->label_apple->setScaledContents(true);
     ui->label_watermelon->setFixedSize(this->width()/4,this->height()/5);
     ui->label_watermelon->setPixmap(QPixmap(":/images/watermelon.png"));
     ui->label_watermelon->setScaledContents(true);
     ui->label_peach->setFixedSize(this->width()/4,this->height()/5);
     ui->label_peach->setPixmap(QPixmap(":/images/peach.png"));
     ui->label_peach->setScaledContents(true);
     ui->label_pineapple->setFixedSize(this->width()/4,this->height()/5);
     ui->label_pineapple->setPixmap(QPixmap(":/images/pineapple.png"));
     ui->label_pineapple->setScaledContents(true);
     ui->label_mango->setFixedSize(this->width()/4,this->height()/5);
     ui->label_mango->setPixmap(QPixmap(":/images/mango.png"));
     ui->label_mango->setScaledContents(true);
     ui->label_orange->setFixedSize(this->width()/4,this->height()/5);
     ui->label_orange->setPixmap(QPixmap(":/images/orrange.png"));
     ui->label_orange->setScaledContents(true);

     //肉类
     ui->label_chicken->setFixedSize(this->width()/4,this->height()/5);
     ui->label_chicken->setPixmap(QPixmap(":/images/chicken.png"));
     ui->label_chicken->setScaledContents(true);
     ui->label_pork->setFixedSize(this->width()/4,this->height()/5);
     ui->label_pork->setPixmap(QPixmap(":/images/pork.png"));
     ui->label_pork->setScaledContents(true);
     ui->label_beef->setFixedSize(this->width()/4,this->height()/5);
     ui->label_beef->setPixmap(QPixmap(":/images/beef.png"));
     ui->label_beef->setScaledContents(true);
     ui->label_fish->setFixedSize(this->width()/4,this->height()/5);
     ui->label_fish->setPixmap(QPixmap(":/images/fish.png"));
     ui->label_fish->setScaledContents(true);
     ui->label_egg->setFixedSize(this->width()/4,this->height()/5);
     ui->label_egg->setPixmap(QPixmap(":/images/egg.png"));
     ui->label_egg->setScaledContents(true);

     int num=ui->stackedWidget->currentIndex();
     connect(ui->btn_change,&QPushButton::clicked,[=]()mutable{
        if(num==2){
            num=0;
        }
        else{
            num++;
        }
        ui->stackedWidget->setCurrentIndex(num);
     });

     connect(ui->btn_save,&QPushButton::clicked,[=](){
         QString date=ui->dateEdit->date().toString("yyyy/MM/dd");
         QString dietstr=ui->lineEdit_diet->text();
         QString currentFilePath = __FILE__;
         QFileInfo fileInfo(currentFilePath);
         QString DirPath = fileInfo.absolutePath() + "/txt";
         QString filepath=DirPath + "/" + user_diet + "/diet.txt";
         QFile file(filepath);
         if(!file.open(QIODevice::Append | QIODevice::Text)){
             qDebug()<<"失败";
         }
 //        else{
 //            qDebug()<<"成功";
 //        }
         QTextStream out(&file);
         out<<date<<"\n";
         out<<dietstr<<"\n";
         file.close();
     });

     QChartView *currentChartView = nullptr;
     connect(ui->btn_diet,&QPushButton::clicked,[=]()mutable{

         std::vector<int> m_diet;
         std::vector<QString> m_date;

         QString currentFilePath = __FILE__;
         QFileInfo fileInfo(currentFilePath);
         QString DirPath = fileInfo.absolutePath() + "/txt";
         QString filepath=DirPath + "/" + user_diet + "/diet.txt";
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
                 if(count%2==0){
                     int num=line.toInt();
                     m_diet.push_back(num);
                 }
                 else{
                     m_date.push_back(line);
                 }
             }
         }
         int n=m_date.size();
 //        for(int i=0;i<n;i++){
 //            qDebug()<<m_weight[i]<<m_date[i];
 //        }
         file_new.close();

         QBarSet *set=new QBarSet("热量");

         for(int i=0;i<n;i++){
             *set<<m_diet[i];
         }

         QBarSeries *series = new QBarSeries();
         series->append(set);

         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setTitle("近期摄入热量变化");
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
         axisY->setRange(0, 5000);
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

         ui->scrollArea_diet->setWidget(container);
     });

}

void DietScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/background_diet.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

DietScene::~DietScene()
{
    delete ui;
}
