#include <vector>
#include "ncurses.h"
#include "Hero.h"
//y x
using namespace std;
class Map {
    public:
        vector<shared_ptr<Character>> mobs;
        int row, col;
        vector<vector<char>> mapChars;
        void initMap(int row, int col);
        void redrawMap();
        void spawnMob(Character ch);
        void showWin();
};
