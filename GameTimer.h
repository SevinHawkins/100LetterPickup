#pragma once
#include <chrono>

class GameTimer {
public:
    GameTimer();
    void start();
    void stop();
    void reset();
    double elapsedSeconds() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    bool running;
};