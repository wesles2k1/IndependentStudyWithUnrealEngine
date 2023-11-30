#pragma once

#include "../AMapSite.h"
#include "../Direction.h"

// Defines a ARoom to be put into a Map
class ARoom: public AMapSite {
    public:
        ARoom(int newRoomID);

        AMapSite* GetSide(Direction direction);
        void SetSide(Direction direction, AMapSite* element);
        void RemoveSide(Direction direction);

        int GetID();

        virtual AMapSite* Enter();

    protected:
        AMapSite* sides[4];
        int roomID{-1};
};