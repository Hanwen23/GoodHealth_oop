#ifndef SLEEPSCENE_H
#define SLEEPSCENE_H

#include <QWidget>

namespace Ui {
class SleepScene;
}

class SleepScene : public QWidget
{
    Q_OBJECT

public:
    explicit SleepScene(QWidget *parent = nullptr);
    ~SleepScene();

    void paintEvent(QPaintEvent *);

    QString user_sleep;



private:
    Ui::SleepScene *ui;
};

#endif // SLEEPSCENE_H
