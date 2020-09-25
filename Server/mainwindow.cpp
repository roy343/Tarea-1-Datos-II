#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mserver = new server(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_iniciar_clicked()
{
    if(!mserver->listen(QHostAddress::Any,ui->puerto->value())){
        QMessageBox::critical(this,"Error",mserver->errorString());
    }else{
        QMessageBox::information(this,"Servidor","Iniciado...");
    }

}

void MainWindow::on_enviar_clicked()
{
    mserver->envia(ui->msj->text());
}

void MainWindow::on_quitar_clicked()
{
    close();
}
