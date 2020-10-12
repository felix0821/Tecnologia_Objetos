cmake_minimum_required(VERSION 3.5)

project(CalculadoraV3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB files "*.h" "*.cpp")

add_executable(CalculadoraV3  ${files}  main.cpp) #linking
