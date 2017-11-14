cmake_minimum_required(VERSION 3.8)
project(splEx1_1)

set(CMAKE_CXX_STANDARD 11)

include_directories(/include)
set(SOURCE_FILES
        src/Commands.cpp
        src/Environment.cpp
        src/FileSystem.cpp
        #src/Main.cpp
        src/Files.cpp
        src/Test.cpp
        )
add_executable(splEx1_1 ${SOURCE_FILES})