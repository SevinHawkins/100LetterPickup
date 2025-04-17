#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    void start();
    long long getElapsedTime() const;

private:
    // Stores the time when the timer was started
    std::chrono::steady_clock::time_point startTime;
};

#endif // TIMER_H
