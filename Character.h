#include "ncurses.h"
class Character {
public:
    int x, y;
    virtual void move(int vec, std::vector<std::shared_ptr<Character>> mobs) = 0;
    virtual void move(std::vector<std::shared_ptr<Character>> mobs) = 0;
    int hp;
    bool isMovable = true;
    char sym;
    int damage;
    int max_hp;
    bool is_dead = false;
};