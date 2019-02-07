#include "Map.h"
class Controller {
    public:
    void init (Map &map1);
    void run(int tik_rate);
    void listen();
    Map map;
    std::shared_ptr<Hero> hero;
};
