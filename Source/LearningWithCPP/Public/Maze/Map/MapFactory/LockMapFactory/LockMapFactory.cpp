#include "LockMapFactory.h"

// Factory Methods

ADoor* LockMapFactory::MakeDoor(ARoom* door1, ARoom* door2) const {
    return nullptr;
    //return new ALockDoor(door1, door2);
}

AWall* LockMapFactory::MakeWall() const {
    return nullptr;
    //return new ALockWall();
}