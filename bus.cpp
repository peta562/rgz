#include "bus.h"

map <string, int> mp = {{"Новосибирск" , 120}, {"Бердск", 180}, {"Искитим", 300}, {"Барнаул", 180}, {"Алтай", 240}};

Clock::Clock(int d, int hr, int mn) : day{d}, hour{hr}, minute{mn}
{
}
Clock::~Clock()
{
}
void Clock::setHour(int hr)
{
    hour = hr;
}
void Clock::setMinute(int mn)
{
    minute = mn;
}
void Clock::setDay(int d)
{
    day = d;
}
int Clock::getDay()
{
    return day;
}
int Clock::getHour()
{
    return hour;
}
int Clock::getMinute()
{
    return minute;
}
void Clock::plusClock(int mn)
{
    mn += minute;
    if(mn >= 0)
    {
        if(mn < 60)
            minute = mn;
        else
        {
            while(mn >= 60)
            {
                mn = mn - 60;
                hour++;
                if(hour >= 24)
                {
                    day++;
                    hour = 0;
                }
            }
            minute = mn;
        }
    }
    else
        cout << "Error value" << endl;
}
void Clock::printTime(QTableWidget* table)
{
    if(hour >= 10 && minute >= 10)
        table->setItem(table->rowCount() -1 , 5, new QTableWidgetItem(QStringLiteral("Date: %1, time: %2::%3").arg(getDay()).arg(getHour()).arg(getMinute())));
    else if (hour < 10 && minute >= 10)
        table->setItem(table->rowCount() -1 , 5, new QTableWidgetItem(QStringLiteral("Date: %1, time: 0%2::%3").arg(getDay()).arg(getHour()).arg(getMinute())));
    else if (hour >= 10 && minute < 10)
        table->setItem(table->rowCount() -1 , 5, new QTableWidgetItem(QStringLiteral("Date: %1, time: %2::0%3").arg(getDay()).arg(getHour()).arg(getMinute())));
    else
        table->setItem(table->rowCount() -1 , 5, new QTableWidgetItem(QStringLiteral("Date: %1, time: 0%2::0%3").arg(getDay()).arg(getHour()).arg(getMinute())));
}




Bus::Bus(int num,int pasNum, int circ, int d, int hr, int mn) : number{num}, passengersNum{pasNum}, circle{circ}, Clock{d, hr, mn}
{

}
Bus::~Bus()
{

}
void Bus::setNum(int n)
{
    number = n;
}
void Bus::setPassNum(int n)
{
    passengersNum = n;
}

void Bus::setCircle(int n)
{
    circle = n;
}
int Bus::getNum()
{
    return number;
}
int Bus::getPassNum()
{
    return passengersNum;
}
int Bus::getCircle()
{
    return circle;
}
void Bus::printInfo()
{
    cout << "Bus number: " << number << endl;
    cout << "Count of passengers: " << passengersNum << endl;
    cout << "Number of laps: " << circle << endl;
}
void Bus::move(QTableWidget* table, int speed, int maxPasNum)
{
    int accident = 0, pasNum;
    int j = 0;
    map <string, int> :: iterator it = mp.begin();
    srand(time(NULL));
    while (j != circle)
    {
        while(it != mp.end())
        {
            for(int i = 0; i < it->second; i += 20)
            {
                accident = 1 + rand() % 100; // вероятность аварии или поломки
                if(accident == 20 || accident == 40 || accident == 80)
                {
                    plusClock(accident / 2); // время устраения аварии или поломки
                }
            }
            pasNum = -5 + rand() % 10; // кол-во пришедших/ушедших пассажиров в автобусе
            passengersNum += pasNum;
            if(passengersNum >= maxPasNum)  // пассажиров не может быть больше, чем вмещает автобус
                setPassNum(maxPasNum);
            if(passengersNum < 0)   // и меньше 0 тоже
                setPassNum(0);
            plusClock(it->second/speed);
            it++;

        }
        while(it != mp.begin())
        {
            for(int i = 0; i < it->second; i += 20)
            {
                accident = 1 + rand() % 100; // вероятность аварии или поломки
                if(accident == 20 || accident == 40 || accident == 80)
                {
                    plusClock(accident / 2); // время устраения аварии или поломки
                }
            }
            pasNum = -5 + rand() % 10; // кол-во пришедших/ушедших пассажиров в автобусе
            passengersNum += pasNum;
            if(passengersNum >= maxPasNum) // пассажиров не может быть больше, чем вмещает автобус
                setPassNum(maxPasNum);
            if(passengersNum < 0) // и меньше 0 тоже
                setPassNum(0);
            plusClock(it->second/speed);
            it--;
        }
       j++;
       table->setItem(table->rowCount() -1 , 1, new QTableWidgetItem(QString::number(getNum())));
       table->setItem(table->rowCount() -1 , 3, new QTableWidgetItem(QString::number(getPassNum())));
       table->setItem(table->rowCount() -1 , 4, new QTableWidgetItem(QString::number(getCircle())));
       Clock::printTime(table);
    }
}


Paz::Paz(int num, int pasNum, int circ, int d, int hr, int mn):Bus(num, pasNum, circ, d, hr, mn)
{
    if(pasNum > maxPasNum)
        pasNum = maxPasNum;
}
Paz::~Paz()
{

}
void Paz::printInfo()
{
    cout << "Model: Paz" << endl;
    Bus::printInfo();
}

void Paz::move(QTableWidget* table)
{
    table->setItem(table->rowCount() -1 , 2, new QTableWidgetItem(QString::number(getPassNum())));
    Bus::move(table, speed, maxPasNum);
}


Vaz::Vaz(int num, int pasNum, int circ, int d, int hr, int mn):Bus(num, pasNum, circ, d, hr, mn)
{
    if(pasNum > maxPasNum)
        pasNum = maxPasNum;
}
Vaz::~Vaz()
{

}
void Vaz::printInfo()
{
    cout << "Model: Vaz" << endl;
    Bus::printInfo();
}

void Vaz::move(QTableWidget* table)
{
    table->setItem(table->rowCount() -1 , 2, new QTableWidgetItem(QString::number(getPassNum())));
    Bus::move(table, speed, maxPasNum);
}




Gaz::Gaz(int num, int pasNum, int circ, int d, int hr, int mn):Bus(num, pasNum, circ, d, hr, mn)
{
    if(pasNum > maxPasNum)
        pasNum = maxPasNum;
}
Gaz::~Gaz()
{

}
void Gaz::printInfo()
{
    cout << "Model: Gaz" << endl;
    Bus::printInfo();
}

void Gaz::move(QTableWidget* table)
{
    table->setItem(table->rowCount() -1 , 2, new QTableWidgetItem(QString::number(getPassNum())));
    Bus::move(table, speed, maxPasNum);
}
