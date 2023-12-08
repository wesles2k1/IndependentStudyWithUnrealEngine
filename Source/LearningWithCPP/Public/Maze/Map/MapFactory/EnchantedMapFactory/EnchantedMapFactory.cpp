#include "EnchantedMapFactory.h"

// Factory Methods

ARoom* EnchantedMapFactory::MakeRoom(int id) const {
    return nullptr;
    // new AEnchantedRoom(id);
}

ADoor* EnchantedMapFactory::MakeDoor(ARoom* door1, ARoom* door2) const {
    return nullptr;
    //return new AEnchantedDoor(door1, door2);
}