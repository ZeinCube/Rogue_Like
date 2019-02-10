#include <iostream>
#include <fstream>
#include "Map.h"
#include <sstream>
#include <unistd.h>

//CAUTION GOVNO CODE

void Map::initMap(int rows, int cols) {
    char buf;
    mapChars.resize(40);
    this->rows = rows;
    this->cols = cols;
    std::ifstream in("map.txt");
    for(int i = 0; i < 40; i++) {
        for(int j = 0; j < 40; j++) {
            buf = in.get();
            mapChars[i].push_back(buf);
        }
    }
}

void Map::showWin() {
    mvaddstr(rows / 2, cols / 2 - 10, "YOU WIN || Press AnyKey");
}

void Map::showLoose() {
    mvaddstr(rows / 2, cols / 2 - 10, "YOU LOOSE || Press AnyKey");
}

void Map::redrawMap() {
    for(int col = 0; col < 40; col++) {
        for(int row = 0; row < 40; row++) {
            mvaddch(((rows - 40) / 2) + row, ((cols - 40) / 2) + col, this->mapChars[col][row]);
        }
        addch('\n');
    }
    stringstream ss;
    for(auto c : mobs) {
        if(!c->is_dead) {
            int x = (rows - 40) / 2 + c->x;
            int y = (cols - 40) / 2 + c->y;
            mvaddch(x, y, c->sym);
        }
    }
    refresh();
}