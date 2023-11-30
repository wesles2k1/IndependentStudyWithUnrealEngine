#pragma once

#include "../MapFactory.h"

#include "../../MapElement/Room/EnchantedRoom/AEnchantedRoom.h"
#include "../../MapElement/Door/EnchantedDoor/AEnchantedDoor.h"

class EnchantedMapFactory: public MapFactory {
    public:
        // Factory Methods
        virtual ARoom* MakeRoom(int id) const;
        virtual ADoor* MakeDoor(ARoom* door1, ARoom* door2) const;

    // Allow for Singleton behavior
    protected:
        EnchantedMapFactory() {};
    friend class Singleton;
};