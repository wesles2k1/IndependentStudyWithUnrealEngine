#pragma once

#include "../ARoom.h"

class AEnchantedRoom: public ARoom {
    public:
        AEnchantedRoom(): ARoom() {};

        virtual AMapSite* Enter();
};