#include "Character.h"

Hero::Hero() {
    hp = 100;
    sym = 'K';
    damage = 15;
    x = 10;
    y = 10;
}

void Hero::collide(Character &c) {
    c.collide(*this);
}

void Hero::collide(Zombie &z) {
    z.hp -= damage;
    hp -= z.damage;
}

void Hero::collide(Princess &p){}

void Hero::collide(Dragon &d) {
    hp -= d.damage;
    d.hp -= damage;
}

void Hero::collide(Hero &h) {}

void Hero::move(int vec, std::vector<std::shared_ptr<Character>> mobs) {
    switch (vec) {
        case KEY_UP:
            for(auto m : mobs) {
                if (x == m->x + 1 && y == m->y) {
                    up = false;
                    collide(*m);
                }
            }
            if(up) {
                if (x > 1)
                    x--;
            }
            break;

        case KEY_DOWN:
            for(auto m : mobs){
                if(x == m->x - 1 && y == m->y) {
                    collide(*m);
                    down = false;
                }
            }
            if(down) {
                if (x < 37)
                    x++;
            }
            break;

        case KEY_RIGHT:
            for(auto m : mobs){
                if(y == m->y - 1 && x == m->x) {
                    collide(*m);
                    right = false;
                }
            }
            if(right) {
                if (y < 38)
                    y++;
            }
            break;
        case KEY_LEFT:
            for(auto m : mobs){

                if(y == m->y + 1 && x == m->x) {
                    collide(*m);
                    left = false;
                }
            }
            if(left) {
                if (y > 1)
                    y--;
            }
            break;
        default:
            break;
    }
    up = down = left = right = true;
}