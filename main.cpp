#include <iostream>
#include <ncurses.h>
#include "Controller.h"
int main() {
    Controller controller;
    int y, x;
    initscr();// Переход в curses-режим
    getmaxyx(stdscr, y, x);
    Map map;
    map.initMap(y, x);
    controller.init(map);
    curs_set(0);
    keypad(stdscr, true);
    controller.run(1);
    endwin();
    return 0;
}