#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "memoryproc.h"
#include "processtest.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCiclo_clicked();

    void on_btnIniciar_clicked();

    void on_btnAddProc_clicked();

private:
    Ui::MainWindow *ui;
    QList<QWidget*> screenList;
    QList<ProcessTest> processList;
    QTimer *timer;
    MemoryProc ram;
    int ciclos = 1;
    void setCurrentScreenTo(QWidget* widget);
};
#endif // MAINWINDOW_H
