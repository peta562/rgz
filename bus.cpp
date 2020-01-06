#include "bus.h"

// маршрут
map <string, int> mp = {{"Новосибирск" , 1200}, {"Бердск", 1800}, {"Искитим", 3000}, {"Барнаул", 1800}, {"Алтай", 2400}};

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
                while(hour >= 24)
                {
                    day++;
                    hour -= 24;
                }
            }
            minute = mn;
        }
    }
    else
        cout << "Error value" << endl;
}
void Clock::printTime(QTableWidget* table) //вывод времени в формате Date: dd, hh:mm
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
int Bus::getMaxPassNum()
{
    return maxPasNum;
}
int Bus::getSpeed()
{
    return speed;
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
void Bus::move(QTableWidget* table)
{
    int accident = 0, pasNum;  //accident - переменная, отвечающая за вероятность поломки/аварии
    int j = 0;
    int countAcc = 0;  // кол-во поломок/аварий
    map <string, int> :: iterator it = mp.begin();
    srand(time(NULL));
    while (j != circle)  //пока не проедем заданное кол-во кругов
    {
        while(it != mp.end())  // двигаемся в один конец маршрута
        {
            for(int i = 0; i < it->second; i += 200)
            {
                accident = 1 + rand() % 100; // вероятность аварии или поломки
                if(accident == 20 || accident == 40)
                {
                    plusClock(accident / 2); // время устраения аварии или поломки
                    countAcc++;
                }
            }
            pasNum = -5 + rand() % 10; // кол-во пришедших/ушедших пассажиров в автобусе
            passengersNum += pasNum;
            if(passengersNum >= getMaxPassNum())  // пассажиров не может быть больше, чем вмещает автобус
                setPassNum(getMaxPassNum());
            if(passengersNum < 0)   // и меньше 0 тоже
                setPassNum(0);
            plusClock(it->second/getSpeed());
            it++;

        }
        while(it != mp.begin())  // двигаемся в другой конец маршрута
        {
            for(int i = 0; i < it->second; i += 200)
            {
                accident = 1 + rand() % 100; // вероятность аварии или поломки
                if(accident == 20 || accident == 40)
                {
                    plusClock(accident / 2); // время устраения аварии или поломки
                    countAcc++;
                }
            }
            pasNum = -5 + rand() % 10; // кол-во пришедших/ушедших пассажиров в автобусе
            passengersNum += pasNum;
            if(passengersNum >= getMaxPassNum()) // пассажиров не может быть больше, чем вмещает автобус
                setPassNum(getMaxPassNum());
            if(passengersNum < 0) // и меньше 0 тоже
                setPassNum(0);
            plusClock(it->second/getSpeed());
            it--;
        }

       j++;
    }
    //записываем значения в таблицу
    table->setItem(table->rowCount() -1 , 1, new QTableWidgetItem(QString::number(getNum())));
    table->setItem(table->rowCount() -1 , 3, new QTableWidgetItem(QString::number(getPassNum())));
    table->setItem(table->rowCount() -1 , 4, new QTableWidgetItem(QString::number(getCircle())));
    table->setItem(table->rowCount() -1 , 6, new QTableWidgetItem(QString::number(countAcc)));
    Clock::printTime(table);
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
int Paz::getMaxPassNum()
{
    return maxPasNum;
}
int Paz::getSpeed()
{
    return speed;
}
void Paz::move(QTableWidget* table)
{
    table->setItem(table->rowCount() -1 , 2, new QTableWidgetItem(QString::number(getPassNum())));
    Bus::move(table);
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
int Vaz::getMaxPassNum()
{
    return maxPasNum;
}
int Vaz::getSpeed()
{
    return speed;
}
void Vaz::move(QTableWidget* table)
{
    table->setItem(table->rowCount() -1 , 2, new QTableWidgetItem(QString::number(getPassNum())));
    Bus::move(table);
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
int Gaz::getMaxPassNum()
{
    return maxPasNum;
}
int Gaz::getSpeed()
{
    return speed;
}
void Gaz::move(QTableWidget* table)
{
    table->setItem(table->rowCount() -1 , 2, new QTableWidgetItem(QString::number(getPassNum())));
    Bus::move(table);
}
