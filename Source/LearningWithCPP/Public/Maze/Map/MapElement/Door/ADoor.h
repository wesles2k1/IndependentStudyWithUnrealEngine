#pragma once

#include "../Room/ARoom.h"

// Defines a ADoor to be put into a Map
class ADoor: public AMapSite {
    public:
        ADoor(ARoom* newRoom1 = nullptr, ARoom* newRoom2 = nullptr);
        
        virtual AMapSite* Enter();
        ARoom* OtherSideFrom(ARoom*);

    protected:
        ARoom* room1{nullptr};
        ARoom* room2{nullptr};
        bool isOpen{false};
};