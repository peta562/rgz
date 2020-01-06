// Программа моделирует движения 3-ех моделей автобусов по маршруту

#include "mainwindow.h"
#include "bus.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
