cmake_minimum_required(VERSION 3.0)

project(bsockets)

#############################
find_package(Boost COMPONENTS system REQUIRED)
if(NOT Boost_FOUND)
    message(SEND_ERROR "Failed to find Boost")
    return()
else()
    include_directories(${Boost_INCLUDE_DIRS})
endif()
##############################

add_executable(bsockets main.cpp)
add_executable(client client.cpp)

target_link_libraries(bsockets ${Boost_LIBRARIES})
target_link_libraries(client ${Boost_LIBRARIES})

install(TARGETS bsockets RUNTIME DESTINATION bin)
install(TARGETS client RUNTIME DESTINATION bin)
