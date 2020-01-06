#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setItemData(0, "Макс кол-во пассажиров - 25", Qt::ToolTipRole);
    ui->comboBox->setItemData(1, "Макс кол-во пассажиров - 20", Qt::ToolTipRole);
    ui->comboBox->setItemData(2, "Макс кол-во пассажиров - 35", Qt::ToolTipRole);
}


void MainWindow::generate() // запускаем автобус
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QString s = ui->comboBox->currentText();
    if(s == "ПАЗ")
    {
        bool notError = true;
        int num = ui->lineEditNum->text().toInt(&notError);
        if(!notError || num <= 0)
        {//если нет ошибки преобразования строки в число
            ui->lineEditNum->setText(QString("Invalid value!"));
            return;
        }
        int passNum = ui->lineEditPassNum->text().toInt(&notError);
        if(!notError || passNum >= 25  || passNum <= 0)
        {
            ui->lineEditPassNum->setText(QString("Invalid value!"));
            return;
        }
        int circle = ui->lineEditCircle->text().toInt(&notError);
        if(!notError || circle < 0)
        {
            ui->lineEditCircle->setText(QString("Invalid value!"));
            return;
        }
        int day = ui->lineEditD->text().toInt(&notError);
        if(!notError || day < 0)
        {
            ui->lineEditD->setText(QString("Invalid value!"));
            return;
        }
        int hr = ui->lineEditH->text().toInt(&notError);
        if(!notError || hr < 0)
        {
            ui->lineEditH->setText(QString("Invalid value!"));
            return;
        }
        int mn = ui->lineEditMn->text().toInt(&notError);
        if(!notError || mn < 0)
        {
            ui->lineEditMn->setText(QString("Invalid value!"));
            return;
        }

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1 , 0, new QTableWidgetItem(QString("PAZ")));
        Paz(num, passNum, circle, day, hr, mn).move(ui->tableWidget);

    }
    else if(s == "ВАЗ")
    {
        bool notError = true;
        int num = ui->lineEditNum->text().toInt(&notError);
        if(!notError || num <= 0)
        {//если нет ошибки преобразования строки в число
            ui->lineEditNum->setText(QString("Invalid value!"));
            return;
        }
        int passNum = ui->lineEditPassNum->text().toInt(&notError);
        if(!notError || passNum >= 20  || passNum <= 0)
        {
            ui->lineEditPassNum->setText(QString("Invalid value!"));
            return;
        }
        int circle = ui->lineEditCircle->text().toInt(&notError);
        if(!notError || circle < 0)
        {
            ui->lineEditCircle->setText(QString("Invalid value!"));
            return;
        }
        int day = ui->lineEditD->text().toInt(&notError);
        if(!notError || day < 0)
        {
            ui->lineEditD->setText(QString("Invalid value!"));
            return;
        }
        int hr = ui->lineEditH->text().toInt(&notError);
        if(!notError || hr < 0)
        {
            ui->lineEditH->setText(QString("Invalid value!"));
            return;
        }
        int mn = ui->lineEditMn->text().toInt(&notError);
        if(!notError || mn < 0)
        {
            ui->lineEditMn->setText(QString("Invalid value!"));
            return;
        }
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1 , 0, new QTableWidgetItem(QString("VAZ")));
        Vaz(num, passNum, circle, day, hr, mn).move(ui->tableWidget);
    }
    else if(s == "ГАЗ")
    {
        bool notError = true;
        int num = ui->lineEditNum->text().toInt(&notError);
        if(!notError || num <= 0)
        {//если нет ошибки преобразования строки в число
            ui->lineEditNum->setText(QString("Invalid value!"));
            return;
        }
        int passNum = ui->lineEditPassNum->text().toInt(&notError);
        if(!notError || passNum >= 35 || passNum <= 0)
        {
            ui->lineEditPassNum->setText(QString("Invalid value!"));
            return;
        }
        int circle = ui->lineEditCircle->text().toInt(&notError);
        if(!notError || circle < 0)
        {
            ui->lineEditCircle->setText(QString("Invalid value!"));
            return;
        }
        int day = ui->lineEditD->text().toInt(&notError);
        if(!notError || day < 0)
        {
            ui->lineEditD->setText(QString("Invalid value!"));
            return;
        }
        int hr = ui->lineEditH->text().toInt(&notError);
        if(!notError || hr < 0)
        {
            ui->lineEditH->setText(QString("Invalid value!"));
            return;
        }
        int mn = ui->lineEditMn->text().toInt(&notError);
        if(!notError || mn < 0)
        {
            ui->lineEditMn->setText(QString("Invalid value!"));
            return;
        }
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1 , 0, new QTableWidgetItem(QString("GAZ")));
        Gaz(num, passNum, circle, day, hr, mn).move(ui->tableWidget);

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

