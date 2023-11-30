#pragma once

#include "../MapFactory.h"

#include "../../MapElement/Room/BombRoom/ABombRoom.h"
#include "../../MapElement/Wall/BombWall/ABombWall.h"

class BombMapFactory: public MapFactory {
    public:
        // Factory Methods
        virtual ARoom* MakeRoom(int id) const;
        virtual AWall* MakeWall() const;

    // Allow for Singleton behavior
    protected:
        BombMapFactory() {};
    friend class Singleton;
};