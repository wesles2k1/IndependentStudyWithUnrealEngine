#include "ABombRoom.h"

AMapSite* ABombRoom::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Entering room! Ah, there's a bomb!!!"));

    return this;
}