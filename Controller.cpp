#include "Controller.h"
#include <unistd.h>
#include "ncurses.h"
#include <thread>

void Controller::init(Map &map1){
    map = map1;
    hero = std::make_shared<Hero>();
    map.hero = hero;
    map.mobs.push_back(std::make_shared<Zombie>());
}

void Controller::listen() {
    while(true) {
        hero->move(getch());
        map.redrawMap();
    }
}

void Controller::run(int sleep_time) {
    std::thread th(&Controller::listen, this);
    while(true) {
        sleep(sleep_time);
        //check for collides
        for(auto o : map.mobs) {
            for(auto a: map.mobs) {

            }
        }
        for(auto m: map.mobs) {
            m->move();
        }
        map.redrawMap();
    }
}
