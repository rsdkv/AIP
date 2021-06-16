# CMakeList.txt: проект CMake для AIP; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (AIP "AIP.cpp" "AIP.h" "input.cpp" "input.h" "output.h" "output.cpp" "submenuNavigator.cpp" "submenuNavigator.h"  "coder.cpp" "decoder.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
