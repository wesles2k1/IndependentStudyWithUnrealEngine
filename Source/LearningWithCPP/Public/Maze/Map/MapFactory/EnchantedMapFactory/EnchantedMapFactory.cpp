#include "EnchantedMapFactory.h"

// Factory Methods

ARoom* EnchantedMapFactory::MakeRoom(int id) const {
    return new AEnchantedRoom(id);
}

ADoor* EnchantedMapFactory::MakeDoor(ARoom* door1, ARoom* door2) const {
    return new AEnchantedDoor(door1, door2);
}