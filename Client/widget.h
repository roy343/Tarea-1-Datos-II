/*
 *@file widget.h
 */
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QLocalSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
   void on_quitar_clicked();

private:
    Ui::Widget *ui;
    QLocalSocket *mSocket;
};
#endif // WIDGET_H
