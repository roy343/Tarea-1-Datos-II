#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QLocalSocket(this);
    mSocket->connectToServer("floyd");

    connect(mSocket,&QLocalSocket::readyRead,[&](){

        QTextStream T(mSocket);

        ui->listWidget->addItem(T.readAll());
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_quitar_clicked()
{
    close();
}
