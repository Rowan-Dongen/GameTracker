#include "Counter.h"

Counter::Counter(int sec, int min, int hour)
{
    this->totalSeconds += sec;
    this->totalSeconds += (min * 60);
    this->totalSeconds += ((hour * 60) * 60);
}
void Counter::TickSecond(int nr)
{
    this->totalSeconds -= nr;
}
void Counter::TickMinute(int nr)
{
    this->totalSeconds -= (nr * 60);
}

void Counter::TickHour(int nr)
{
    this->totalSeconds -= ((nr * 60) * 60);
}

int Counter::GetTotalSeconds()
{
    return totalSeconds;
}

int Counter::GetTotalMinutes()
{
    return (totalSeconds / 60);
}

int Counter::GetTotalHours()
{
    return ((totalSeconds / 60) / 60);
}

void Counter::AddSeconds(int nr)
{
    totalSeconds += nr;
}
void Counter::AddMinutes(int nr)
{
    totalSeconds += (nr * 60);
}