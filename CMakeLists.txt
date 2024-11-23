cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CMAKE_CXX_STANDARD 23)

project(create_cpp)

file(GLOB SRC src/**.cpp)

add_executable(create_cpp ${SRC})

install(TARGETS ${PROJECT_NAME})
