cmake_minimum_required(VERSION 3.9)
project(Program)

set(CMAKE_CXX_STANDARD 11)

add_executable(CircularLinkedList.cpp Main.cpp ItemType.cpp CircularLinkedList.h ItemType.h)
