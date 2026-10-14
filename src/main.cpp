#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>

#include "cpu_temperature.hpp"
#include "system_state.hpp"

void displayTemperature(double temperature, unsigned long elapsedMs)
{
    const SystemState state = evaluateTemperature(temperature);

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
        std::cout << " FAULT=OVER_TEMPERATURE";
    }

    std::cout << '\n';
}

int main()
{
    std::cout << "============================================\n";
    std::cout << " Embedded Safety Monitoring Node\n";
    std::cout << " Raspberry Pi 4 / Embedded Linux\n";
    std::cout << "============================================\n\n";

    unsigned long elapsedMs = 0;

    const auto cpuTemperature = readCpuTemperatureCelsius();

    if (cpuTemperature.has_value())
    {
        std::cout << "Temperature source: Raspberry Pi CPU\n\n";

        for (int i = 0; i < 10; ++i)
        {
            const auto temperature =
                readCpuTemperatureCelsius();

            if (!temperature.has_value())
            {
                std::cerr
                    << "ERROR: Unable to read CPU temperature.\n";

                return 1;
            }

            displayTemperature(
                temperature.value(),
                elapsedMs
            );

            std::this_thread::sleep_for(
                std::chrono::milliseconds(500)
            );

            elapsedMs += 500;
        }
    }
    else
    {
        std::cout << "Temperature source: Simulation\n\n";

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

        for (double temperature : temperatures)
        {
            displayTemperature(
                temperature,
                elapsedMs
            );

            std::this_thread::sleep_for(
                std::chrono::milliseconds(500)
            );

            elapsedMs += 500;
        }
    }

    std::cout << "\nMonitoring completed.\n";

    return 0;
}
