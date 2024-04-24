#ifndef COUNTER_H
#define COUNTER_H


class Counter
{
private:
    unsigned long totalSeconds = 0;

public:
    Counter(int sec, int min, int hour);

    void TickMinute(int nr);
    void TickSecond(int nr);
    void TickHour(int nr);

    int GetTotalSeconds();
    int GetTotalMinutes();
    int GetTotalHours();

    void AddSeconds(int nr);
    void AddMinutes(int nr);

    // int GetMinutes();
    // int GetSeconds();
    // int GetHours();
};



#endif