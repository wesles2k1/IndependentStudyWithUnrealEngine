#pragma once

#include "../AWall.h"

class ALockWall: public AWall {
    public:
        ALockWall(): AWall() {};

        virtual AMapSite* Enter();
};