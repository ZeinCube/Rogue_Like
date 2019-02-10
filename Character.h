#pragma once

#include "ncurses.h"
#include <vector>
#include <memory>

class Dragon;

class Princess;

class Zombie;

class Hero;

class Character {
public:
    int x, y;

    //void move(int vec, std::vector<std::shared_ptr<Character>> mobs);
    virtual void move(std::vector<std::shared_ptr<Character>> mobs) = 0;

    virtual void collide(Character &c) = 0;

    virtual void collide(Zombie &z) = 0;

    virtual void collide(Princess &p) = 0;

    virtual void collide(Dragon &d) = 0;

    virtual void collide(Hero &h) = 0;

    int hp;
    int iteration = 0;
    bool goUp = true;
    char sym;
    int damage;
    bool is_dead = false;
};

class Hero : public Character {
public:
    bool isWin = false;
    bool down = true, up = true, left = true, right = true;

    Hero();

    void move(std::vector<std::shared_ptr<Character>> mobs) {}

    void collide(Princess &p) override;

    void collide(Dragon &d) override;

    void collide(Hero &h) override;

    void collide(Character &c) override;

    void collide(Zombie &z) override;

    void move(int vec, std::vector<std::shared_ptr<Character>> mobs);
};

class Zombie : public Character {
public:
    Zombie(int x_, int y_);

    int range = 10;

    bool isNear(Character &c2);

    void move(std::vector<std::shared_ptr<Character>> mobs) override;

    void collide(Princess &p) override;

    void collide(Dragon &d) override;

    void collide(Hero &h) override;

    void collide(Character &c) override;

    void collide(Zombie &z) override;
};


class Dragon : public Character {
public:
    int range = 8;
    int iteration = 0;

    Dragon(int x_, int y_);

    void collide(Princess &p) override;

    void collide(Dragon &d) override;

    void collide(Hero &h) override;

    void collide(Character &c) override;

    void collide(Zombie &z) override;

    bool isNear(Character &c2);

    void move(std::vector<std::shared_ptr<Character>> mobs) override;

};

class Princess : public Character {
public:
    Princess();

    void collide(Princess &p) override {}

    void collide(Dragon &d) override {}

    void collide(Hero &h) override;

    void collide(Character &c) override {}

    void collide(Zombie &z) override {}

    void move(std::vector<std::shared_ptr<Character>> mobs){}
};

