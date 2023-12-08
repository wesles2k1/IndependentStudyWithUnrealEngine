#pragma once

#include "../ABombRoom.h"

class AAtomicBombRoom: public ABombRoom {
    public:
        AAtomicBombRoom(): ABombRoom() {};

        virtual AMapSite* Enter();
};