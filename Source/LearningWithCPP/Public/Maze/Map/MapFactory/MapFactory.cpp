#include "MapFactory.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// ------ //
// Public //
// ------ //

// Factory Methods

ARoom* MapFactory::MakeRoom(int id) const {
    ARoom* room{nullptr};
    if(GetWorld() != nullptr) {
        room = GetWorld()->SpawnActor<ARoom>();
        room->Initialize(id);
        // Set Material!
    }
    return room;
}

AWall* MapFactory::MakeWall() const {
    AWall* wall{nullptr};
    if(GetWorld() != nullptr) {
        wall = GetWorld()->SpawnActor<AWall>();
        wall->Initialize();
        // Set Material!
    }
    return wall;
}

ADoor* MapFactory::MakeDoor(ARoom* room1, ARoom* room2) const {
    ADoor* door{nullptr};
    if(GetWorld() != nullptr) {
        door = GetWorld()->SpawnActor<ADoor>();
        door->Initialize(room1, room2);
        // Set Material!
    }
    return door;
}

void MapFactory::SetWorld(UWorld* world) {
    worldRef = world;
}

UWorld* MapFactory::GetWorld() const {
    return worldRef;
}
