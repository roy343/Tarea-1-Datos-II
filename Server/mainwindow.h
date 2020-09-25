#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class server;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_iniciar_clicked();

    void on_enviar_clicked();

    void on_quitar_clicked();

private:
    Ui::MainWindow *ui;
    server *mserver;
};
#endif // MAINWINDOW_H
