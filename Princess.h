#include <vector>
class Princess : public Character{
public:
    Princess(){
        hp = 1;
        sym = 'P';
        damage = 0;
        x = 15;
        y = 22;
    }

    void move(int vec, std::vector<std::shared_ptr<Character>>){
        return;
    }

    void move(std::vector<std::shared_ptr<Character>> mobs){
        return;
    }
};

