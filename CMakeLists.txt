cmake_minimum_required(VERSION 3.16)

project(
    EmbeddedSafetyMonitoringNode
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    safety_monitor
    src/main.cpp
)

target_include_directories(
    safety_monitor
    PRIVATE
    include
)

add_executable(
    test_logic
    tests/test_logic.cpp
)

target_include_directories(
    test_logic
    PRIVATE
    include
)

enable_testing()

add_test(
    NAME DiagnosticLogicTests
    COMMAND test_logic
)