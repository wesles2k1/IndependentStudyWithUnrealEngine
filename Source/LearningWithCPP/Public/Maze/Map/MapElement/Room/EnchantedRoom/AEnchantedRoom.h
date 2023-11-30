#pragma once

#include "../ARoom.h"

class AEnchantedRoom: public ARoom {
    public:
        AEnchantedRoom(int id): ARoom(id) {};

        virtual AMapSite* Enter();
};