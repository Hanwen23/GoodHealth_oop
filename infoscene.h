#ifndef INFOSCENE_H
#define INFOSCENE_H

#include <QWidget>

namespace Ui {
class InfoScene;
}

class InfoScene : public QWidget
{
    Q_OBJECT

public:
    explicit InfoScene(QWidget *parent = nullptr);
    ~InfoScene();

    void paintEvent(QPaintEvent *);

    QString user_info;


private:
    Ui::InfoScene *ui;
};

#endif // INFOSCENE_H
