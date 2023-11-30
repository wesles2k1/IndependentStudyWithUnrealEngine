#pragma once

#include "../AWall.h"

class ABombWall: public AWall {
    public:
        ABombWall(): AWall() {};

        virtual AMapSite* Enter();
};