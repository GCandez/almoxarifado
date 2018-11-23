cmake_minimum_required(VERSION 3.9)

project(almoxarifado VERSION 2.0 LANGUAGES C)

include("libs/gtest/googletest-download.cmake")

add_subdirectory(almoxarifado.core)
add_subdirectory(almoxarifado.core.tests)
