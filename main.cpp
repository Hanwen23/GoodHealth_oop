#include "logscene.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogScene w;
    w.show();
    return a.exec();
}
