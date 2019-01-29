cmake_minimum_required(VERSION 3.1.1)
project(STLSample)
set(SRC_LIST  main.cpp Tool.h Tool.cpp TemplateClass.cpp)
add_executable(STLSample ${SRC_LIST})