#include "MapFactory.h"

// ------ //
// Public //
// ------ //

// Factory Methods

ARoom* MapFactory::MakeRoom(int id) const {
    return new ARoom(id);
}

AWall* MapFactory::MakeWall() const {
    return new AWall();
}

ADoor* MapFactory::MakeDoor(ARoom* room1, ARoom* room2) const {
    return new ADoor(room1, room2);
}