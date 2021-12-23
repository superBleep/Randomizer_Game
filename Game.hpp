#ifndef GAME_HPP
#define GAME_HPP

#include <ctime>
#include <type_traits>

template <typename T>
int game(Hero &hero, T &enemy, std::ostream &fout);

#include "Game.cpp"

#endif