#pragma once

#include "../MapFactory.h"

#include "../../MapElement/Door/LockDoor/ALockDoor.h"
#include "../../MapElement/Wall/LockWall/ALockWall.h"

class LockMapFactory: public MapFactory {
    public:
        // Factory Methods
        virtual ADoor* MakeDoor(ARoom* door1, ARoom* door2) const;
        virtual AWall* MakeWall() const;

    // Allow for Singleton behavior
    protected:
        LockMapFactory() {};
    friend class Singleton;
};