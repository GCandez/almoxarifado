cmake_minimum_required(VERSION 3.12)
project(almoxarifado.core.tests LANGUAGES CXX)

include(GoogleTest)

add_executable(almoxarifado.core.tests LinkedListTests.cpp)
gtest_discover_tests(almoxarifado.core.tests)

target_link_libraries(almoxarifado.core.tests gtest gtest_main almoxarifado.core)