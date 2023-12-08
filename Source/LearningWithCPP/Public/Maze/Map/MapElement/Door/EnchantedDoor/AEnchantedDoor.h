#pragma once

#include "../ADoor.h"

// Defines a ARoom to be put into a Map
class AEnchantedDoor: public ADoor {
    public:
        AEnchantedDoor(ARoom* door1, ARoom* door2): ADoor() {};

        virtual AMapSite* Enter();
};