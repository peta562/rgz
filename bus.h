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
    void plusClock(int mn);
    void printTime(QTableWidget* table);
};


class Bus : public Clock
{
protected:
    int number;
    int passengersNum;
    int circle;

public:
    Bus(int num = 1,int pasNum = 0, int circ = 1, int d = 0, int hr = 9, int mn = 0);
    virtual ~Bus();
    void setNum(int n);
    void setPassNum(int n);
    void setCircle(int n);
    int getNum();
    int getPassNum();
    int getCircle();
    void printInfo();
    void move(QTableWidget* table, int speed = 1, int maxPasNum = 0);
};

class Paz : public Bus
{
private:
    int speed = 30;
    int maxPasNum = 25;
public:
    Paz(int num = 0,int pasNum = 0, int circ = 1, int d = 0, int hr = 9, int mn = 0);
    ~Paz();
    void printInfo();
    void setSpeed();
    void move(QTableWidget* table);
};

class Vaz : public Bus
{
private:
    int speed = 20;
    int maxPasNum = 20;
public:
    Vaz(int num = 0,int pasNum = 0, int circ = 1, int d = 0, int hr = 9, int mn = 0);
    ~Vaz();
    void printInfo();
    void setSpeed();
    void move(QTableWidget* table);
};

class Gaz : public Bus
{
private:
    int speed = 60;
    int maxPasNum = 35;
public:
    Gaz(int num = 0,int pasNum = 0, int circ = 1, int d = 0, int hr = 9, int mn = 0);
    ~Gaz();
    void printInfo();
    void setSpeed();
    void move(QTableWidget* table);
};



#endif // BUS_H
