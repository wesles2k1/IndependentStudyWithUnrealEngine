#include "AWall.h"

AWall::AWall() {
    root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = root;

    mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    mesh->SetupAttachment(root);
}

void AWall::Initialize() {
    
}

AMapSite* AWall::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Ran into wall!"));

    return this;
}