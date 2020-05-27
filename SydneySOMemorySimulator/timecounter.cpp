#include "timecounter.h"
#include <QtDebug>
#include <cstdlib>
#include <dos.h> //for delay


int TimeCounter::getTimepass() const
{
    return timepass;
}

void TimeCounter::setTimepass(int value)
{
    timepass = value;
}

TimeCounter::TimeCounter()
{
    timepass = 0;
}

void TimeCounter::counter()
{
    while(true){
        _sleep(1000);
        //delay(1000);
        timepass++;
        qDebug()<<timepass;
    }
}




