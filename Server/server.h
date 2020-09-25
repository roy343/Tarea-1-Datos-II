#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalServer>

class QLocalSocket;

class Server : public QLocalServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void envia(const QString &msj);
private:
    QLocalSocket *mSocket;
signals:

};

#endif // SERVER_H
