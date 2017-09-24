cmake_minimum_required(VERSION 3.8)
project(dataStructure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp myList/homework1_1.c myList/homework1_2.c myList/homework1_3.c myList/MyList.c myList/MyList.h school/XXX.cpp school/FastPower.cpp myStack/MyStack.c myStack/MyStack.h otherPeople/hello.cpp myStack/BracketsMatch.c)
add_executable(dataStructure ${SOURCE_FILES})