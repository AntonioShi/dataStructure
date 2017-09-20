cmake_minimum_required(VERSION 3.8)
project(dataStructure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp data_structure/homework1_1.c data_structure/homework1_2.c data_structure/homework1_3.c data_structure/MyList.c data_structure/MyList.h school/XXX.cpp school/FastPower.cpp)
add_executable(dataStructure ${SOURCE_FILES})