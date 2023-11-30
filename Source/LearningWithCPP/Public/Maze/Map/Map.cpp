#include "Map.h"

AMap::AMap() {
    
}

void AMap::AddRoom(ARoom* newRoom) {
    roomStorage.push_back(newRoom);
}

ARoom* AMap::GetRoom(int id) const {
    return roomStorage[id];
}
