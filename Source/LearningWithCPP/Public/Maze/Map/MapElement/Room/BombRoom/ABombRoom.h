#pragma once

#include "../ARoom.h"

class ABombRoom: public ARoom {
    public:
        ABombRoom(int id): ARoom(id) {};

        virtual AMapSite* Enter();
};