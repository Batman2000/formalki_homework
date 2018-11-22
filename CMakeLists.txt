cmake_minimum_required(VERSION 3.10)
project(formalki)


set(CMAKE_CXX_STANDARD 14)

add_executable(Out main.cpp engine.h)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable (
        RunTests
        tests.h
        tester.cpp
)

target_link_libraries(RunTests ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()
add_test(Tests RunTests)