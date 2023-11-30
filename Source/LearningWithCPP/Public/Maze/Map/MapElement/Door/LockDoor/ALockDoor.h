#pragma once

#include "../ADoor.h"

// Defines a ARoom to be put into a Map
class ALockDoor: public ADoor {
    public:
        ALockDoor(ARoom* door1, ARoom* door2): ADoor(door1, door2) {};

        virtual AMapSite* Enter();
};