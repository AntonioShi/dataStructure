cmake_minimum_required(VERSION 3.8)
project(dataStructure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp homework/chapter02/homework1_1.c homework/chapter02/homework1_2.c homework/chapter02/homework1_3.c myList/MyList.c myList/MyList.h school/XXX.cpp school/FastPower.cpp myStack/MyStack.c myStack/MyStack.h otherPeople/hello.cpp myStack/BracketsMatch.c myStack/InfixToSuffix.c homework/chapter03/homework3_1.cpp homework/chapter03/homework3_2.cpp homework/chapter03/homework3_3.cpp experiment/experiment01.cpp otherPeople/ghjkl.cpp experiment/experiment02.cpp otherPeople/arrayQueue.cpp otherPeople/Polynomial.cpp)
add_executable(dataStructure ${SOURCE_FILES})