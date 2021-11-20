project(Randomizer_Game)

add_executable(${PROJECT_NAME} Player.hpp Hero.hpp Enemy.hpp Armor.hpp Weapon.hpp exceptions.hpp main.cpp)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
endif()