cmake_minimum_required(VERSION 2.6)

set (SRCS
TestResult.cpp
TestSuite.cpp
)

set (HEADERS
../include/UnitTest/Assert.hh
../include/UnitTest/TestCase.hpp
../include/UnitTest/TestResult.hh
../include/UnitTest/TestSuite.hh
)

add_library(UnitTestLibrary SHARED ${SRCS} ${HEADERS})

TARGET_LINK_LIBRARIES(UnitTestLibrary CoreLibrary)