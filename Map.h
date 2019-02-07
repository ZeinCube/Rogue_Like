#include <vector>
#include "Character.h"
#include "ncurses.h"
//y x
using namespace std;
class Map {
    public:
        shared_ptr<Hero> hero;
        vector<shared_ptr<Character>> mobs;
        int row, col;
        vector<vector<char>> mapChars;
        void initMap(int row, int col);
        void redrawMap();
        void spawnMob(Character ch);
};
