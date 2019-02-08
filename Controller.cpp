#include "Controller.h"
#include <unistd.h>
#include "ncurses.h"
#include <thread>

void Controller::init(Map &map1){
    map = map1;
    hero = std::make_shared<Hero>();
//    map.mobs.emplace_back(std::make_shared<Zombie>());
    map.mobs.emplace_back(std::make_shared<Zombie>());
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
    th.detach();
    while(true) {
        sleep(sleep_time);
        for(auto it = map.mobs.begin(); it != map.mobs.end(); it++){
            if(it->get()->is_dead)
                map.mobs.erase(it);
        }
        if (hero->is_dead)
            break;
        for(auto m: map.mobs) {
            m->move(map.mobs);
        }
        map.redrawMap();
    }
}
