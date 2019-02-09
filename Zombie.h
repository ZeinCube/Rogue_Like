#include "Character.h"

class Zombie : public Character {
public:
    int range = 10;
    int position_iter = 0;

    Zombie(int x_, int y_) {
        hp = 20;
        sym = 'Z';
        damage = 10;
        x = x_;
        y = y_;
    }

    void collade(Character &c) {
        switch (c.sym) {
            case 'K':
                if (hp > 0) {
                    c.hp -= damage;
                    hp -= c.damage;
                    if (hp <= 0)
                        is_dead = true;
                    if (c.hp <= 0)
                        is_dead = true;
                } else { is_dead = true;}
                break;
            case 'D':

                break;
        }
    }

    bool isNear(Character &c2) {
        bool res = false;
        if (x == c2.x + 1 && y == c2.y) {
            goLeft = true; //go up, hero is under me
            position_iter = 10;
            res = true;
        }
        if (x == c2.x - 1 && y == c2.y) {
            goLeft = false;
            position_iter = 0;
            res = true;
        }
        return res;
    }

    void move(std::vector<std::shared_ptr<Character>> mobs) {
        for (auto m : mobs) {
            if (isNear(*m))
                collade(*m);
        }
        switch (goLeft) { // true = down, false = up
            case true :
                if (x < 37) {
                    x++;
                    position_iter++;
                    if (position_iter == range)
                        goLeft = false;
                } else { goLeft = false; }
                break;
            case false:
                if (x > 1) {
                    x--;
                    position_iter--;
                    if (position_iter == 0)
                        goLeft = true;
                    break;
                } else { goLeft = true; }
                break;
        }
    }
};