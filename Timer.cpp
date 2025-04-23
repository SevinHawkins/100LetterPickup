#include <chrono>

class Timer {
public:
    void Timer::start() {
        startTime = std::chrono::steady_clock::now();
    }

    long long Timer::getElapsedTime() const {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime);
        return elapsed.count();
    }

private:
    std::chrono::steady_clock::time_point startTime;
};
