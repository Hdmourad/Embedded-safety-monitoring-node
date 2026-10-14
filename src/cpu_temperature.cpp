#include "cpu_temperature.hpp"

#include <fstream>

std::optional<double> readCpuTemperatureCelsius()
{
#ifdef __linux__

    const char* temperaturePath =
        "/sys/class/thermal/thermal_zone0/temp";

    std::ifstream temperatureFile(temperaturePath);

    if (!temperatureFile.is_open())
    {
        return std::nullopt;
    }

    double milliCelsius = 0.0;

    temperatureFile >> milliCelsius;

    if (temperatureFile.fail())
    {
        return std::nullopt;
    }

    return milliCelsius / 1000.0;

#else

    return std::nullopt;

#endif
}
