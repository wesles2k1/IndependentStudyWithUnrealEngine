#include "BombMapFactory.h"

// Factory Methods

ARoom* BombMapFactory::MakeRoom(int id) const {
    return nullptr;
    //return new ABombRoom(id);
}

AWall* BombMapFactory::MakeWall() const {
    return nullptr;
    //return new ABombWall();
}