# CMake generated Testfile for 
# Source directory: /home/bivan/Amperka04/workspace/projects/RK2
# Build directory: /home/bivan/Amperka04/workspace/projects/RK2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AllTests "/home/bivan/Amperka04/workspace/projects/RK2/build/tests")
set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "/home/bivan/Amperka04/workspace/projects/RK2/CMakeLists.txt;33;add_test;/home/bivan/Amperka04/workspace/projects/RK2/CMakeLists.txt;0;")
subdirs("third-party/gtest")
