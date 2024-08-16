#ifndef LOGSCENE_H
#define LOGSCENE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LogScene; }
QT_END_NAMESPACE

class LogScene : public QWidget
{
    Q_OBJECT

public:

    LogScene(QWidget *parent = nullptr);
    ~LogScene();

    void paintEvent(QPaintEvent *);

private:
    Ui::LogScene *ui;
};
#endif // LOGSCENE_H
