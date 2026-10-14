#include <cassert>
#include <iostream>

#include "system_state.hpp"

int main()
{
    assert(
        evaluateTemperature(25.0)
        == SystemState::NORMAL
    );

    assert(
        evaluateTemperature(60.0)
        == SystemState::NORMAL
    );

    assert(
        evaluateTemperature(60.1)
        == SystemState::WARNING
    );

    assert(
        evaluateTemperature(75.0)
        == SystemState::WARNING
    );

    assert(
        evaluateTemperature(75.1)
        == SystemState::FAULT
    );

    assert(
        evaluateTemperature(100.0)
        == SystemState::FAULT
    );

    std::cout
        << "All diagnostic tests passed.\n";

    return 0;
}