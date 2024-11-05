cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(rational)

include_directories(include)

add_library(${PROJECT_NAME} SHARED
			src/rational.cpp)

add_executable(main src/main.cpp)

target_link_libraries(main ${PROJECT_NAME})

install(TARGETS main DESTINATION $ENV{HOME}/Local/bin)
