#include "EnchantedRoom.h"

MapSite* EnchantedRoom::Enter() {
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Entering room, there's a strange aura here!"));

    return this;
}