#include "Character.h"
class Zombie : public Character {
public:
    int range = 10;
    int position_iter = 0;

    Zombie(){
        hp = 20;
        sym = 'Z';
        damage = 20;
        x = 30;
        y = 45;
    }

    void move(int vec, std::vector<std::shared_ptr<Character>> mobs){
        return;
    }

    void collade(Character &c){
        switch (c.sym){
            case 'K':
                c.hp -= damage;
                hp -= c.damage;
                if(hp == 0)
                    is_dead = true;
                if(c.hp == 0)
                    is_dead = true;
                break;
        }
    }

    bool isNear (Character &c2) {
        bool res = false;
        if(x == c2.x + 1 && y == c2.y) {
            isMovable = true; //go up, hero is under me
            position_iter = 10;
            res = true;
        }
        if(x == c2.x - 1 && y == c2.y) {
            isMovable = false;
            position_iter = 0;
            res = true;
        }
        return res;
    }

    void move(std::vector<std::shared_ptr<Character>> mobs) {
        for(auto m : mobs){
            if(isNear(*m))
                collade(*m);
        }
        switch (isMovable) { // true = down, false = up
            case true :
                if (x < 50) {
                    x++;
                    position_iter++;
                    if (position_iter == range)
                        isMovable = false;
                } else { isMovable = false; }
                break;
            case false:
                if (x > 14) {
                    x--;
                    position_iter--;
                    if (position_iter == 0)
                        isMovable = true;
                    break;
                } else { isMovable = true; }
                break;
            }
    }
};