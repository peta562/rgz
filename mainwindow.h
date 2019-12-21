#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bus.h"
#include "QStandardItemModel"
#include "QStandardItem"

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
    void generate();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
