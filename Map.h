#include <vector>
#include "ncurses.h"
#include "Hero.h"
//y x
using namespace std;
class Map {
    public:
        vector<shared_ptr<Character>> mobs;
        int rows, cols;
        vector<vector<char>> mapChars;
        void initMap(int rows, int cols);
        void redrawMap();
        void spawnMob(Character ch);
        void showWin();
};
