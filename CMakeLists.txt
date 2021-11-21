project(Randomizer_Game)

add_executable(${PROJECT_NAME} main.cpp)

if(MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic" "-g" "-std=c++11")
endif()