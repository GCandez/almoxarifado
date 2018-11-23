cmake_minimum_required(VERSION 3.9)

project(almoxarifado VERSION 2.0 LANGUAGES C)

add_subdirectory(almoxarifado.core)

include(cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )
enable_testing()

add_subdirectory(almoxarifado.core.tests)
