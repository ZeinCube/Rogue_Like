#include "Controller.h"
#include <unistd.h>
#include "ncurses.h"
#include <thread>

void Controller::init(Map &map1){
    map = map1;
    hero = std::make_shared<Hero>();
    map.mobs.push_back(std::make_shared<Zombie>());
    map.mobs.push_back(hero);
}

void Controller::listen() {
    while(true) {
        hero->move(getch(), map.mobs);
        map.redrawMap();
    }
}

void Controller::run(int sleep_time) {
    std::thread th(&Controller::listen, this);
    while(true) {
        sleep(sleep_time);
        if (hero->is_dead)
            break;
        for(auto m: map.mobs) {
            if(!m->is_dead)
            m->move(map.mobs);
            else map.mobs.erase(std::remove(map.mobs.begin(), map.mobs.end(), m));
        }
        map.redrawMap();
    }
}
