#include "Zombie.h"
class Hero: public Character {
public:
    bool down = true, up = true, left = true, right = true;
    Hero() {
        hp = 100;
        sym = 'K';
        damage = 20;
        x = 20;
        y = 40;
    }

    void move(std::vector<std::shared_ptr<Character>> mobs){
        return;
    }

    void collade(Character &c){
        switch(c.sym) {
            case 'Z':
                c.hp -= damage;
                if(c.hp == 0)
                    c.is_dead = true;
                c.isMovable = !c.isMovable;
                hp -= c.damage;
                if (hp == 0)
                    is_dead = true;
                break;
            default:
                break;
        }
    }

    bool isOnWay(Character &c2, int vec) {
        bool res = false;
        switch (vec) {
            case KEY_UP:
                    if (x == c2.x + 1 && y == c2.y) {
                        up = false;
                        res = true;
                    }
                break;
            case KEY_DOWN:
                    if (x == c2.x - 1 && y == c2.y) {
                        down = false;
                        res = true;
                    }
                break;
            case KEY_LEFT:
                    if (y == c2.y + 1 && x == c2.x) {
                        left = false;
                        res = true;
                    }
                break;
            case KEY_RIGHT:
                    if (y == c2.y - 1 && x == c2.x) {
                        right = false;
                        res = true;
                    }
                break;

            default:
                break;
        }
            return res;
    }

    void move(int vec, std::vector<std::shared_ptr<Character>> mobs) {
            switch (vec) {
                case KEY_UP:
                    for(auto m : mobs){
                        if(isOnWay(*m, KEY_UP))
                            collade(*m);
                    }
                    if(up) {
                        if (x > 14)
                            x--;
                    }
                    break;

                case KEY_DOWN:
                    for(auto m : mobs){
                        if(isOnWay(*m, KEY_DOWN))
                            collade(*m);
                    }
                    if(down) {
                        if (x < 50)
                            x++;
                    }
                    break;

                case KEY_RIGHT:
                    for(auto m : mobs){
                        if(isOnWay(*m, KEY_RIGHT))
                            collade(*m);
                    }
                    if(right) {
                        if (y < 58)
                            y++;
                    }
                    break;

                case KEY_LEFT:
                    for(auto m : mobs){
                        if(isOnWay(*m, KEY_LEFT))
                            collade(*m);
                    }
                    if(left) {
                        if (y > 21)
                            y--;
                    }
                    break;

                default:
                    0;
            }
        up = down = left = right = true;
    }
};