#include "ncurses.h"

class Character {
public:
    int x, y;
    virtual void collade(Character &ch) = 0;
    virtual void move(int vec) = 0;
    virtual void move() = 0;
    int hp;
    bool isMovable = true;
    char sym;
    int damage;
    int max_hp;
};

class Zombie;

class Hero: public Character {
public:
    Hero() {
        hp = 100;
        sym = 'K';
        damage = 10;
        x = 20;
        y = 40;
    }

    void collade(Character &ch) {
        ch.collade(*this);
    }

    void collade(Zombie &z);

    void move(){
        return;
    }

    void move(int vec) {
        switch (vec){
            case KEY_UP:
                if(x > 14)
                x--;
                break;
            case KEY_DOWN:
                if(x < 50)
                x++;
                break;
            case KEY_RIGHT:
                if(y < 58)
                y++;
                break;
            case KEY_LEFT:
                if(y > 21)
                y--;
                break;
            default: 0;
        }
    }
};

class Zombie : public Character {
    public:
    int range = 10;
    int position_iter = 0;
    bool go_down = true;

    Zombie(){
        hp = 20;
        sym = 'Z';
        damage = 20;
        x = 30;
        y = 40;
    }

    void move(int vec){
        return;;
    }

    void collade(Character &ch){
        ch.collade(*this);
    }

    void collade(Zombie &z){
        z.go_down = !go_down;
        z.collade(*this);
    }

    bool collade(Hero &h){
        h.hp -= this->damage;
        h.collade(*this);
        return true;
    }

    void move() {
        if (isMovable) {
            switch (go_down) {
                case true :
                    if (x < 50) {
                        x++;
                        position_iter++;
                        if (position_iter == range)
                            go_down = false;
                    } else { go_down = false; }
                    break;
                case false:
                    if (x > 14) {
                        x--;
                        position_iter--;
                        if (position_iter == 0)
                            go_down = true;
                        break;
                    } else { go_down = true; }
            }
        } else {
        isMovable = true;
    }
};

void Hero::collade(Zombie &z) {
    z.hp -= this->damage;
}