cmake_minimum_required(VERSION 3.0.0)

project(Time)


aux_source_directory("./Src" SourceDir)
add_executable(Time ${SourceDir})

