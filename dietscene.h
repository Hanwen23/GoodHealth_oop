#ifndef DIETSCENE_H
#define DIETSCENE_H

#include <QWidget>

namespace Ui {
class DietScene;
}

class DietScene : public QWidget
{
    Q_OBJECT

public:
    explicit DietScene(QWidget *parent = nullptr);
    ~DietScene();

    QString user_diet;

    void paintEvent(QPaintEvent *);

private:
    Ui::DietScene *ui;
};

#endif // DIETSCENE_H
