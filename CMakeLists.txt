CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    cindys_unit_tests.cpp
    visitor_tests_gaby.cpp
    cindys_visitor_tests.cpp
    gabys_unit_tests.cpp
    preorder_iterator.cpp
    binary_iterator.cpp
    visitor.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)