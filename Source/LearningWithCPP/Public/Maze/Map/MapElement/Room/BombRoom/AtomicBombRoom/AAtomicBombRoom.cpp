#include "AAtomicBombRoom.h"

AMapSite* AAtomicBombRoom::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Entering room! Oh, there's just a HUGE bomb in here. Pretty dangerous, but it's probably alright. Just don't make it angry."));

    return this;
}