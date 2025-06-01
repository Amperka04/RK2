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

# DEB package configuration
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "rk2-patterns")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VENDOR "Your Name")
set(CPACK_PACKAGE_CONTACT "your.email@example.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Command Pattern Implementation")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14)")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
include(CPack)
