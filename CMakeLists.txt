project(Randomizer_Game)

cmake_minimum_required(VERSION 3.21)

add_executable(${PROJECT_NAME} Player.cpp Hero.cpp Enemy.cpp main.cpp)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic" "-g")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options("-stdlib=libstdc++")
    endif()
endif()