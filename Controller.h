#include "Map.h"
#include <mutex>
class Controller {
    public:
    bool isWin = false;
    void init (Map &map1);
    void clearMobs();
    std::mutex mut;
    void run();
    Map map;
    std::shared_ptr<Hero> hero;
};
