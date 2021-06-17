# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("AIP")

add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)

#подключаем тесты 
enable_testing()
add_subdirectory(external/doctest)
include(external/doctest/doctest.cmake)
include_directories(external/doctest)

# Включите подпроекты.
add_subdirectory ("AIP")
