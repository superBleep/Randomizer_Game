#ifndef GAME_HPP
#define GAME_HPP

#include "Hero.hpp"
#include "Boss.hpp"
#include "Sub_Boss.hpp"
#include <ctime>
#include <type_traits>

template <typename T>
int game(Hero &hero, T &enemy, std::ostream &fout);

#include "Game.cpp"

#endif