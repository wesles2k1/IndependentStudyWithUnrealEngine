#pragma once

#include "../AMapSite.h"

// Defines a AWall to be put into a Map
class AWall: public AMapSite {
    public:
        AWall();

        virtual AMapSite* Enter();
};