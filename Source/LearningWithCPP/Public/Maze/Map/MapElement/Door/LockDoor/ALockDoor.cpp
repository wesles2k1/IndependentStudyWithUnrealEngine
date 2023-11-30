#include "ALockDoor.h"

AMapSite* ALockDoor::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("This door has a big ol' lock on it."));

    return this;
}