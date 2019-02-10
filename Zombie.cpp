#include "Character.h"

Zombie::Zombie(int x_, int y_) {
    hp = 20;
    sym = 'Z';
    damage = 10;
    x = x_;
    y = y_;
}

bool Zombie::isNear(Character &c2) {
    bool res = false;
    if (x == c2.x + 1 && y == c2.y) {
        goUp = true; //go up, hero is under me
        iteration = 10;
        res = true;
    }
    if (x == c2.x - 1 && y == c2.y) {
        goUp = false;
        iteration = 0;
        res = true;
    }
    return res;
}

void Zombie::move(std::vector<std::shared_ptr<Character>> mobs) {
    for (auto m : mobs) {
        if (isNear(*m))
            collide(*m);
    }
    if (goUp) {
        if (x < 37) {
            x++;
            iteration++;
            if (iteration == range)
                goUp = false;
        } else { goUp = false; }
    } else {
        if (x > 1) {
            x--;
            iteration--;
            if (iteration == 0)
                goUp = true;
        } else { goUp = true; }
    }
}


void Zombie::collide(Character &c) {
    c.collide(*this);
}

void Zombie::collide(Hero &h) {
    hp -= h.damage;
    h.hp -= damage;
    goUp = !goUp;
}

void Zombie::collide(Dragon &d) {
    goUp = !goUp;
    hp -= d.damage;
}

void Zombie::collide(Zombie &z) {
    goUp = !goUp;
}

void Zombie::collide(Princess &p) {
    goUp = !goUp;
}