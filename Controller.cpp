#include "Controller.h"
#include <unistd.h>
#include "ncurses.h"
#include <thread>
#include "Princess.h"
#include "Dragon.h"

void Controller::init(Map &map1){
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

void Controller::listen() {
    while(!hero->isWin && !hero->is_dead) {
        for(auto it = map.mobs.begin(); it != map.mobs.end(); it++){
            if(it->get()->is_dead)
                map.mobs.erase(it);
        }
        map.redrawMap();
        hero->move(getch(), map.mobs);
        map.redrawMap();
    }
}

void Controller::run(int sleep_time) {
    std::thread th(&Controller::listen, this);
    th.detach();
    while(!hero->isWin && !hero->is_dead) {
        for(auto it = map.mobs.begin(); it != map.mobs.end(); it++){
            if(it->get()->is_dead)
                if(it->get()->sym != 'K')
                    map.mobs.erase(it);
        }
        sleep(sleep_time);
        if (hero->is_dead)
            break;
        for(auto m: map.mobs) {
            if(!m->is_dead)
            m->move(map.mobs);
        }
        map.redrawMap();
    }
    if(!hero->is_dead)
    map.showWin();
    getch();
}