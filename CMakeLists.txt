#cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
#add_executable(runTests test.cpp)
#target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

cmake_minimum_required (VERSION 2.6)

option(test "Build all tests." OFF)

# executable
project (stats)
add_executable(main main.cpp)
add_definitions(-std=c++11)

# UT
# to enable please use 
# cmake -Dtest=ON

if (test)
	enable_testing()
	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS})
	add_executable(runTests test.cpp)
	target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
endif()
