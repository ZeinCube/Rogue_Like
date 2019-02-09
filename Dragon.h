#include <vector>
class Dragon : public Character {
public:
    int range = 8;
    int iteration = 0;

    Dragon(int x_, int y_){
        hp = 60;
        sym = 'D';
        damage = 25;
        x = x_;
        y = y_;
    }

    void collade(Character &c){
        switch (c.sym){
            case 'K':
                if(hp > 0) {
                    c.hp -= damage;
                    hp -= c.damage;
                    if (hp <= 0)
                        is_dead = true;
                    if (c.hp <= 0)
                        c.is_dead = true;
                } else { is_dead = true;
                }
                break;
            case 'Z':
                goLeft = !goLeft;
                break;
        }
    }

    bool isNear (Character &c2) {
        bool res = false;
        if(y == c2.y + 1 && x == c2.x) {
            goLeft = true;
            iteration = range;
            res = true;
        }
        if(y == c2.y - 1 && x == c2.x) {
            goLeft = false;
            iteration = 0;
            res = true;
        }
        return res;
    }

    void move(std::vector<std::shared_ptr<Character>> mobs) {
        for(auto m : mobs){
            if(isNear(*m))
                collade(*m);
        }
        switch (goLeft) {
            case true :
                if (y < 38) {
                    y++;
                    iteration++;
                    if (iteration >= range)
                        goLeft = false;
                } else { goLeft = false; }
                break;
            case false:
                if (y > 1) {
                    y--;
                    iteration--;
                    if (iteration <= 0)
                        goLeft = true;
                    break;
                } else { goLeft = true; }
                break;
        }
    }
};