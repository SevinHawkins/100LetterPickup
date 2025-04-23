#include "GameTimer.h"

GameTimer::GameTimer() : running(false) {}

void GameTimer::start() {
    startTime = std::chrono::high_resolution_clock::now();
    running = true;
}

void GameTimer::stop() {
    if (running) {
        endTime = std::chrono::high_resolution_clock::now();
        running = false;
    }
}

void GameTimer::reset() {
    running = false;
}

double GameTimer::elapsedSeconds() const {
    if (running) {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(now - startTime).count();
    } else {
        return std::chrono::duration<double>(endTime - startTime).count();
    }
}