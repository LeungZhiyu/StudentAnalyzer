cmake_minimum_required(VERSION 3.16)

project(StudentAnalyzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StudentAnalyzer src/main.cpp src/student.cpp)

target_include_directories(StudentAnalyzer PRIVATE include)
