#ifndef SPORTSCENE_H
#define SPORTSCENE_H

#include <QWidget>

namespace Ui {
class SportScene;
}

class SportScene : public QWidget
{
    Q_OBJECT

public:
    explicit SportScene(QWidget *parent = nullptr);
    ~SportScene();

    void paintEvent(QPaintEvent *);

    QString user_sport;

    int step_standard;

private:
    Ui::SportScene *ui;
};

#endif // SPORTSCENE_H
