#include "AEnchantedDoor.h"

AMapSite* AEnchantedDoor::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Passing through door! You feel magical!"));

    return this;
}