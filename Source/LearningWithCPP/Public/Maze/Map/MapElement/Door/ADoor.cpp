#include "ADoor.h"

ADoor::ADoor() {
    root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = root;

    mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    mesh->SetupAttachment(root);
}

void ADoor::Initialize(ARoom* newRoom1, ARoom* newRoom2) {
    room1 = newRoom1;
    room2 = newRoom2;
}

AMapSite* ADoor::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Passing through door!"));

    return this;
}

ARoom* ADoor::OtherSideFrom(ARoom* currentSide) {
    if(room1 == currentSide) {
        return room2;
    } else if(room2 == currentSide) {
        return room1;
    } else {
        return nullptr;
    }
}