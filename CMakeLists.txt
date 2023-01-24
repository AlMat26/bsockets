cmake_minimum_required(VERSION 3.0)

project(bsockets)

add_executable(bsockets main.cpp)

install(TARGETS bsockets RUNTIME DESTINATION bin)
