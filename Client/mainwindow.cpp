#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead,[&](){
        QTextStream T(mSocket);
        ui->listWidget->addItem(T.readAll());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    mSocket->connectToHost(ui->server->text(),ui->port->value());
}

void MainWindow::on_pushButton_clicked()
{

}
