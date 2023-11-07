#include "Door.h"

Door::Door(Room* newRoom1, Room* newRoom2) {
    room1 = newRoom1;
    room2 = newRoom2;
}

MapSite* Door::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Passing through door!"));

    return this;
}

Room* Door::OtherSideFrom(Room* currentSide) {
    if(room1 == currentSide) {
        return room2;
    } else if(room2 == currentSide) {
        return room1;
    } else {
        return nullptr;
    }
}