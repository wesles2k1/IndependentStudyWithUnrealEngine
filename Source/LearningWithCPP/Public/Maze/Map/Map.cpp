#include "Map.h"

AMap::AMap() {
    
}

void AMap::AddRoom(Room* newRoom) {
    roomStorage.push_back(newRoom);
}

Room* AMap::GetRoom(int id) const {
    return roomStorage[id];
}