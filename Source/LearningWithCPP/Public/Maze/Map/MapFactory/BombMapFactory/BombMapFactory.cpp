#include "BombMapFactory.h"

// Factory Methods

ARoom* BombMapFactory::MakeRoom(int id) const {
    return new ABombRoom(id);
}

AWall* BombMapFactory::MakeWall() const {
    return new ABombWall();
}