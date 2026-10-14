#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>

#include "system_state.hpp"

int main()
{
    std::cout << "============================================\n";
    std::cout << " Embedded Safety Monitoring Node\n";
    std::cout << " Raspberry Pi 4 / Embedded Linux\n";
    std::cout << "============================================\n\n";

    const std::vector<double> temperatures =
    {
        25.0,
        32.5,
        58.0,
        63.5,
        70.0,
        82.0,
        45.0
    };

    unsigned long elapsedMs = 0;

    for (double temperature : temperatures)
    {
        const SystemState state =
            evaluateTemperature(temperature);

        std::cout
            << "["
            << std::setw(6)
            << std::setfill('0')
            << elapsedMs
            << " ms] "
            << "TEMP="
            << std::fixed
            << std::setprecision(1)
            << temperature
            << " C "
            << "STATE="
            << stateToString(state);

        if (state == SystemState::FAULT)
        {
            std::cout
                << " FAULT=OVER_TEMPERATURE";
        }

        std::cout << '\n';

        std::this_thread::sleep_for(
            std::chrono::milliseconds(500)
        );

        elapsedMs += 500;
    }

    std::cout
        << "\nMonitoring simulation completed.\n";

    return 0;
}