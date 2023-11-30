#pragma once

#include "../ABombRoom.h"

class AAtomicBombRoom: public ABombRoom {
    public:
        AAtomicBombRoom(int id): ABombRoom(id) {};

        virtual AMapSite* Enter();
};