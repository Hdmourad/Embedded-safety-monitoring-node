
cmake_minimum_required(VERSION 3.16)

project(
    EmbeddedSafetyMonitoringNode
    VERSION 0.2.0
    LANGUAGES C CXX
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Programme principal existant
add_executable(
    safety_monitor
    src/main.cpp
    src/cpu_temperature.cpp
)

target_include_directories(
    safety_monitor
    PRIVATE
    include
)

# Module de diagnostic écrit en C
add_library(diagnostics STATIC
    src/diagnostics.c
)

target_include_directories(
    diagnostics
    PUBLIC
    include
)

# Test C++ existant
add_executable(
    test_logic
    tests/test_logic.cpp
)

target_include_directories(
    test_logic
    PRIVATE
    include
)

# Nouveau test du module C
add_executable(
    test_diagnostics
    tests/test_diagnostics.c
)

target_link_libraries(
    test_diagnostics
    PRIVATE
    diagnostics
)

enable_testing()

add_test(
    NAME DiagnosticLogicTests
    COMMAND test_logic
)

add_test(
    NAME DiagnosticsCTests
    COMMAND test_diagnostics
)
