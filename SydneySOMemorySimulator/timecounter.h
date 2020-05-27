#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H
#include <QTime>
#include <QTimer>
#include <chrono>

class TimeCounter
{
   int timepass;

public:
    TimeCounter();


    void counter();
    int getTimepass() const;
    void setTimepass(int value);
};

#endif // TIMECOUNTER_H
