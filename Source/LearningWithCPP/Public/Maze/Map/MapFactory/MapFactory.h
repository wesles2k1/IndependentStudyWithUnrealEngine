#pragma once

#include <iostream>

#include "../MapElement/MapElementInclude.h"

class MapFactory {
    public:
        // Factory Methods
        virtual ARoom* MakeRoom(int id) const;
        virtual AWall* MakeWall() const;
        virtual ADoor* MakeDoor(ARoom* door1, ARoom* door2) const;
    
    // Allow for Singleton behavior
    protected:
        MapFactory() {};
    friend class Singleton;
};