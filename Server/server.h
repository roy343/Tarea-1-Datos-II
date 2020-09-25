#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class QTcpSocket;

class server : public QTcpServer
{
public:
    server();
    explicit server(QObject *parent = 0);
    void envia(const QString &msj);
private:
    QTcpSocket *mSocket;
};

#endif // SERVER_H
