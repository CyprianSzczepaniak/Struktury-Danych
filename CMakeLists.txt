cmake_minimum_required(VERSION 3.29.6)
project(Projekt1_StrukturyDanych)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt1_StrukturyDanych main.cpp Tab.cpp Tab.hpp
        SinglyLinkedList.cpp
        SinglyLinkedList.hpp
)
