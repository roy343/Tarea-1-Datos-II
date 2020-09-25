#include "mainwindow.h"
#include "floydwarshall.cpp"

#include <QApplication>
#include<QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
