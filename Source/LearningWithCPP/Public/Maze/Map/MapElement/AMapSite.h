#pragma once

// Defines a component of the map/part of the room
class AMapSite {
    public:
        virtual ~AMapSite() = default;
        virtual AMapSite* Enter() = 0;
};