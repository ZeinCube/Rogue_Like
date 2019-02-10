#include "Character.h"

Princess::Princess() {
    hp = 1;
    sym = 'P';
    damage = 0;
    x = 2;
    y = 2;
}

void Princess::collide(Hero &h) {
    h.isWin = true;
}
