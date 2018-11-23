cmake_minimum_required(VERSION 3.9)
project(almoxarifado.core.tests LANGUAGES CXX)

include("${CMAKE_SOURCE_DIR}/cmake/gtest.cmake")

add_executable(almoxarifado.core.tests LinkedListTests.cpp)

target_link_libraries(almoxarifado.core.tests gtest gtest_main almoxarifado.core)

gtest_add_tests(TARGET almoxarifado.core.tests
                SOURCES LinkedListTests.cpp)