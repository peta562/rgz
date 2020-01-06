#ifndef BUS_H
#define BUS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include <QPlainTextEdit>
#include <QTableWidget>
#include <QMainWindow>
#include "QStandardItemModel"
#include "QStandardItem"

using namespace std;

class Clock
{
protected:
    int hour;
    int minute;
    int day;
public:
    Clock(int d = 0, int hr = 9, int mn = 0);
    ~Clock();
    void setHour(int hr);
    void setMinute(int mn);
    void setDay(int d);
    int getDay();
    int getHour();
    int getMinute();
    void plusClock(int mn); // прибавление времени после пройденной остановки или починки
    void printTime(QTableWidget* table); // вывод времени
};


class Bus : public Clock
{
private:
    int maxPasNum = 0; // максимальное кол-во пассажиров
    int speed = 1; // скорость автобуса
protected:
    int number;
    int passengersNum;
    int circle;
public:
    Bus(int num = 0,int pasNum = 0, int circ = 1, int d = 0, int hr = 9, int mn = 0);
    virtual ~Bus();
    void setNum(int n);
    void setPassNum(int n);
    void setCircle(int n);
    int getNum();
    int getPassNum();
    virtual int getSpeed();
    int getCircle();
    virtual int getMaxPassNum();
    void printInfo();
    void move(QTableWidget* table); // функция движения по маршруту, пока не закончится кол-во заданных кругов
};

class Paz : public Bus
{
private:
    int speed = 40;
    int maxPasNum = 25;
public:
    Paz(int num = 0,int pasNum = 0, int circ = 1, int d = 0, int hr = 9, int mn = 0);
    ~Paz() override;
    void printInfo();
    int getMaxPassNum() override;
    int getSpeed() override;
    void move(QTableWidget* table);
};

class Vaz : public Bus
{
private:
    int speed = 50;
    int maxPasNum = 20;
public:
    Vaz(int num = 0,int pasNum = 0, int circ = 1, int d = 0, int hr = 9, int mn = 0);
    ~Vaz() override;
    void printInfo();
    int getMaxPassNum() override;
    int getSpeed() override;
    void move(QTableWidget* table);
};

class Gaz : public Bus
{
private:
    int speed = 60;
    int maxPasNum = 35;
public:
    Gaz(int num = 0,int pasNum = 0, int circ = 1, int d = 0, int hr = 9, int mn = 0);
    ~Gaz() override;
    void printInfo();
    int getMaxPassNum() override;
    int getSpeed() override;
    void move(QTableWidget* table);
};



#endif // BUS_H
