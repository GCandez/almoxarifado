cmake_minimum_required(VERSION 3.9)
project(almoxarifado.core.tests LANGUAGES CXX)

include(GoogleTest)

add_executable(almoxarifado.core.tests LinkedListTests.cpp)
gtest_add_tests(TARGET almoxarifado.core.tests
                SOURCES LinkedListTests.cpp.cpp)

target_link_libraries(almoxarifado.core.tests gtest gtest_main almoxarifado.core)