#pragma once

#include "../MapFactory.h"

#include "../../MapElement/Door/LockDoor/LockDoor.h"
#include "../../MapElement/Wall/LockWall/LockWall.h"

class LockMapFactory: public MapFactory {
    public:
        // Factory Methods
        virtual Door* MakeDoor(Room* door1, Room* door2) const;
        virtual Wall* MakeWall() const;

    // Allow for Singleton behavior
    protected:
        LockMapFactory() {};
    friend class Singleton;
};