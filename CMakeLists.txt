cmake_minimum_required(VERSION 3.21)

project(Randomizer_Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic" "-g")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options("-stdlib=libstdc++")
    endif()
endif()

add_executable(${PROJECT_NAME} Player.cpp Hero.cpp Enemy.cpp Sub_Hero.cpp main.cpp)