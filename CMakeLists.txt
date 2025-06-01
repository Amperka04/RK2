cmake_minimum_required(VERSION 3.10)
project(RK2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third-party/gtest)

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/third-party/gtest/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/third-party/gtest/googlemock/include)


add_library(Patterns STATIC
    src/WebPageManager.cpp
    src/ChangeWebPageCommand.cpp
    src/Button.cpp
)


add_executable(main_exe src/main.cpp)
target_link_libraries(main_exe Patterns)


enable_testing()
add_executable(tests
    tests/WebPageManagerTest.cpp
    tests/ChangeWebPageCommandTest.cpp
    tests/GenericCommandTest.cpp
    tests/ButtonTest.cpp
)
target_link_libraries(tests Patterns gtest gtest_main gmock)
add_test(NAME AllTests COMMAND tests)
