#pragma once

#include "../ARoom.h"

class ABombRoom: public ARoom {
    public:
        ABombRoom(): ARoom() {};

        virtual AMapSite* Enter();
};