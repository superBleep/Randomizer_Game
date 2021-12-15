project(Randomizer_Game)

cmake_minimum_required(VERSION 3.21)

add_executable(${PROJECT_NAME} Player.cpp Hero.cpp Enemy.cpp Sub_Hero.cpp main.cpp)

if(MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic" "-std=c++17" "-g")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options("-stdlib=libstdc++")
    endif()
endif()