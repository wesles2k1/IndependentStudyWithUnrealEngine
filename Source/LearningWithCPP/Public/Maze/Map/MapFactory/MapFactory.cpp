#include "MapFactory.h"

// ------ //
// Public //
// ------ //

// Factory Methods

Room* MapFactory::MakeRoom(int id) const {
    return new Room(id);
}

Wall* MapFactory::MakeWall() const {
    return new Wall();
}

Door* MapFactory::MakeDoor(Room* room1, Room* room2) const {
    return new Door(room1, room2);
}