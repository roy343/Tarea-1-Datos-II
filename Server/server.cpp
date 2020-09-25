#include "server.h"
#include <QTcpSocket>
#include <QTextStream>

server::server(QObject *parent) : QTcpServer(parent)
{
    mSocket = nullptr;

    connect(this,&server::newConnection,[&](){
        mSocket = nextPendingConnection();
    });
}

void server::envia(const QString &msj)
{
    if(mSocket){
    QTextStream T(mSocket);
    T << msj;
    mSocket->flush();
    }
}
