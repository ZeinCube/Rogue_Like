#include <iostream>
#include <fstream>
#include "Map.h"
#include <sstream>

//CAUTION GOVNO CODE

void Map::initMap(int row, int col) {
    char buf;
    mapChars.resize(40);
    this->row = row;
    this->col = col;
    std::ifstream in("map.txt");
    for(int i = 0; i < 40; i++) {
        for(int j = 0; j < 40; j++) {
            buf = in.get();
            mapChars[i].push_back(buf);
        }
    }
}

void Map::showWin() {
    mvaddstr(row / 2, col / 2, "YOU WIN");
}

void Map::redrawMap() {
    for(int cols = 0; cols < 40; cols++) {
        for(int rows = 0; rows < 40; rows++) {
            mvaddch(((row - 40) / 2) + rows, ((col - 40) / 2) + cols, this->mapChars[cols][rows]);
        }
        addch('\n');
    }
    stringstream ss;
    for(auto c : mobs) {
        mvaddch(c->x, c->y, c->sym);
        ss << c->sym << ": " << c->hp << " ";
    }
    std::string s = ss.str();
    const char* str = s.c_str();
    mvaddstr(row - 1, 1, str);
    refresh();
}