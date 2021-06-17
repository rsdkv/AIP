# CMakeList.txt: проект CMake для AIP; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (AIP "AIP.cpp" "input.cpp" "output.cpp" "submenuNavigator.cpp" "coder.cpp" "decoder.cpp" "allcodersinfo.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
add_executable(AIP_test "test.cpp" "input.cpp" "output.cpp" "submenuNavigator.cpp" "coder.cpp" "decoder.cpp" "allcodersinfo.cpp")
target_link_libraries(AIP_test PUBLIC doctest::doctest default)
doctest_discover_tests(AIP_test)