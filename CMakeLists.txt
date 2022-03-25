cmake_minimum_required(VERSION 3.0.0)

project(Time)

file( GLOB_RECURSE HEADER_FILES  ./inc/*.h  ./inc*.inl )
file( GLOB_RECURSE SOURCE_FILES  ./src/*.c* )
message( STATUS "HEADER_FILES: ${HEADER_FILES}" )
message( STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}" )

add_executable(Time ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(Time PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
