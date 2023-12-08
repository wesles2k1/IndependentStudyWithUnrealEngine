#pragma once

#include <iostream>

#include "../MapElement/MapElementInclude.h"

class MapFactory {
    public:
        // Factory Methods
        virtual ARoom* MakeRoom(int id) const;
        virtual AWall* MakeWall() const;
        virtual ADoor* MakeDoor(ARoom* door1, ARoom* door2) const;

        void SetWorld(UWorld* world);
        UWorld* GetWorld() const;
    
    private:
        // Reference to the world to spawn within
        UWorld* worldRef{nullptr};
    
    // Allow for Singleton behavior
    protected:
        MapFactory() {};
    friend class Singleton;
};