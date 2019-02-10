#include "Controller.h"
#include <unistd.h>
#include "ncurses.h"
#include <thread>
#include "Character.h"
//#include "Dragon.h"

void Controller::init(Map &map1) {
    map = map1;
    hero = std::make_shared<Hero>();
    map.mobs.emplace_back(std::make_shared<Princess>());
    map.mobs.emplace_back(std::make_shared<Zombie>(11, 1));
    map.mobs.emplace_back(std::make_shared<Zombie>(11, 3));
    map.mobs.emplace_back(std::make_shared<Zombie>(11, 5));
    map.mobs.emplace_back(std::make_shared<Zombie>(2, 7));
    map.mobs.emplace_back(std::make_shared<Zombie>(3, 7));
    map.mobs.emplace_back(std::make_shared<Zombie>(14, 8));
    map.mobs.emplace_back(std::make_shared<Zombie>(2, 2));
    map.mobs.emplace_back(std::make_shared<Zombie>(4, 6));
    map.mobs.emplace_back(std::make_shared<Dragon>(8, 6));
    map.mobs.emplace_back(hero);
}

void Controller::clearMobs() {
    mut.lock();
    for (auto it = map.mobs.begin(); it != map.mobs.end(); it++) {
        if (it->get()->hp <= 0)
            map.mobs.erase(it);
    }
    map.redrawMap();
    mut.unlock();
}

void Controller::run() {
    timeout(100);
    while (!hero->isWin && hero->hp > 0) {
        clearMobs();
        hero->move(getch(), map.mobs);
        if (hero->hp <= 0)
            map.showLoose();
        for (auto m: map.mobs) {
            if (m->hp > 0)
                m->move(map.mobs);
        }
    }
    if (hero->hp <= 0) {
        map.showLoose();
    } else {
        map.showWin();
    }
    timeout(4000);
    getch();
}