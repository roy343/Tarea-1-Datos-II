#include "server.h"
#include <QLocalSocket>
#include <QTextStream>

Server::Server(QObject *parent) : QLocalServer(parent)
{
 mSocket = nullptr;

 connect(this, &Server::newConnection,[&](){
   mSocket = nextPendingConnection();
   QTextStream T(mSocket);
 });
}

void Server ::envia(const QString &msj){
    if(mSocket){
    QTextStream T(mSocket);
    T<<msj;
    mSocket->flush();
    }
}
