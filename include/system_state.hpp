#pragma once

#include <string>

enum class SystemState
{
    NORMAL,
    WARNING,
    FAULT
};

inline SystemState evaluateTemperature(double temperature)
{
    if (temperature > 75.0)
    {
        return SystemState::FAULT;
    }

    if (temperature > 60.0)
    {
        return SystemState::WARNING;
    }

    return SystemState::NORMAL;
}

inline std::string stateToString(SystemState state)
{
    switch (state)
    {
        case SystemState::NORMAL:
            return "NORMAL";

        case SystemState::WARNING:
            return "WARNING";

        case SystemState::FAULT:
            return "FAULT";
    }

    return "UNKNOWN";
}