/*
 *@file server.cpp
 */

#include "server.h"
#include <QLocalSocket>
#include <QTextStream>

/*
 *@class Server
 *@brief clase principal del server
 */

Server::Server(QObject *parent) : QLocalServer(parent)
{
 mSocket = nullptr;

 connect(this, &Server::newConnection,[&](){
   mSocket = nextPendingConnection();
   QTextStream T(mSocket);
 });
}


/*
 *@brief Funcion para enviar informacion al cliente
 */

void Server ::envia(const QString &msj){
    if(mSocket){
    QTextStream T(mSocket);
    T<<msj;
    mSocket->flush();
    }
}
