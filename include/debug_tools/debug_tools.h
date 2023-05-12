#pragma once

#include <chrono>
#include <iostream>

namespace DebugTools {
    class Timer
    {
    public:
        Timer();
        ~Timer();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
    };
}