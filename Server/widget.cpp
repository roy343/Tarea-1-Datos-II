#include "widget.h"
#include "ui_widget.h"
#include "server.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mServer = new Server(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_iniciar_clicked()
{
    if(!mServer->listen("floyd")){
        QMessageBox::critical(this,"Error!",mServer->errorString());
    }else{
    QMessageBox::information(this,"Servidor","Iniciado....");
    }
}

void Widget::on_enviar_clicked()
{
    mServer->envia(ui->msj->text());
}

void Widget::on_quitar_clicked()
{
    close();
}
