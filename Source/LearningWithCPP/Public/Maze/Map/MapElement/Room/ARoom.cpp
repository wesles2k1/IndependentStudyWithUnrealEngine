#include "ARoom.h"

#include "Components/StaticMeshComponent.h"

ARoom::ARoom() {
    root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = root;

    mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    mesh->SetupAttachment(root);
}

void ARoom::Initialize(int newRoomID) {
    roomID = newRoomID;
}

AMapSite* ARoom::GetSide(Direction direction) {
    AMapSite* returnElement{nullptr};

    switch (direction) {
        case Direction::North:
            returnElement = sides[0];
            break;
        case Direction::East:
            returnElement = sides[1];
            break;
        case Direction::South:
            returnElement = sides[2];
            break;
        case Direction::West:
            returnElement = sides[3];
            break;
        case Direction::Default:
        default:
            returnElement = nullptr;
    }

    return returnElement;
}

void ARoom::SetSide(Direction direction, AMapSite* element) {
    switch (direction) {
        case Direction::North:
            sides[0] = element;
            break;
        case Direction::East:
            sides[1] = element;
            break;
        case Direction::South:
            sides[2] = element;
            break;
        case Direction::West:
            sides[3] = element;
            break;
        case Direction::Default:
            break;
    }
}

void ARoom::RemoveSide(Direction direction) {
    switch (direction) {
        case Direction::North:
            delete sides[0];
            sides[0] = nullptr;
            break;
        case Direction::East:
            delete sides[1];
            sides[1] = nullptr;
            break;
        case Direction::South:
            delete sides[2];
            sides[2] = nullptr;
            break;
        case Direction::West:
            delete sides[3];
            sides[3] = nullptr;
            break;
        case Direction::Default:
            break;
    }
}

int ARoom::GetID() {
    return roomID;
}

AMapSite* ARoom::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Entering room!"));

    return this;
}