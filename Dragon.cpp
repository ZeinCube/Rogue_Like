#include "Character.h"

Dragon::Dragon(int x_, int y_) {
    hp = 60;
    sym = 'D';
    damage = 25;
    x = x_;
    y = y_;
}

void Dragon::collide(Character &c) {
    c.collide(*this);
}

void Dragon::collide(Hero &h) {
    h.hp -= damage;
    hp -= h.damage;
    goUp = !goUp;
}

void Dragon::collide(Zombie &z) {
    goUp = !goUp;
    z.hp -= damage;
}

void Dragon::collide(Princess &p) {
    goUp = !goUp;
}

void Dragon::collide(Dragon &d) {
    goUp = !goUp;
}


bool Dragon::isNear(Character &c2) {
    bool res = false;
    if (y == c2.y + 1 && x == c2.x) {
        goUp = true;
        iteration = range;
        res = true;
    }
    if (y == c2.y - 1 && x == c2.x) {
        goUp = false;
        iteration = 0;
        res = true;
    }
    return res;
}

void Dragon::move(std::vector<std::shared_ptr<Character>> mobs) {
    for (auto m : mobs) {
        if (isNear(*m))
            collide(*m);
    }
    if (goUp) {
        if (y < 38) {
            y++;
            iteration++;
            if (iteration >= range)
                goUp = false;
        } else { goUp = false; }
    } else {
        if (y > 1) {
            y--;
            iteration--;
            if (iteration <= 0)
                goUp = true;
        } else { goUp = true; }
    }
}