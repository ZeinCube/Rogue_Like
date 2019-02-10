cmake_minimum_required(VERSION 3.12)
project(Rogue_Like)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rogue_Like main.cpp Map.cpp Map.h Controller.cpp Controller.h Character.h Hero.cpp Zombie.cpp Dragon.cpp Princess.cpp)

set(CMAKE_CXX_FLAGS "-lncurses")