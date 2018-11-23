cmake_minimum_required(VERSION 3.12)

project(almoxarifado.core VERSION 2.0 LANGUAGES C)

set(include_path "${almoxarifado.core_SOURCE_DIR}/include")
set(header_path "${include_path}/almoxarifado.core")
set(source_path  "${almoxarifado.core_SOURCE_DIR}")

set(header_files
    "${header_path}/LinkedList.h")

set(src_files
    "${source_path}/LinkedList.c")

add_library(almoxarifado.core ${header_files} ${src_files})

target_include_directories(almoxarifado.core PUBLIC ${include_path})