/*
 *@file widget.cpp
 */

#include "widget.h"
#include "ui_widget.h"
#include "server.h"
#include <QMessageBox>
#include "floydwarshall.cpp"

#define V 4
#define INF 99





int graph[V][V] = { {0, 5, INF, 10},
                    {INF, 0, 3, INF},
                    {INF, INF, 0, 1},
                    {INF, INF, INF, 0}
                };

/*
 *@brief Inicia la interfaz del cliente y define el socket
 */

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

/*
 *@brief Al apretar el boton "iniciar" se inicia el servidor
 */
void Widget::on_iniciar_clicked()
{
    if(!mServer->listen("floyd")){
        QMessageBox::critical(this,"Error!",mServer->errorString());
    }else{
    QMessageBox::information(this,"Servidor","Iniciado....");
    }
}

/*
 *@brief se envia un mensaje al cliente
 */
void Widget::on_enviar_clicked()
{
    mServer->envia(ui->msj->text());
}


/*
 *@file cierra el cliente
 */
void Widget::on_quitar_clicked()
{
    close();
}
