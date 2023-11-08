#include "MapType.h"

// ------ //
// Public //
// ------ //

MapFactory* UMapTypeProcessor::ToMapFactory(EMapType inputMapType) {
    MapFactory* returnFactory;

    switch(inputMapType) {
        case EMapType::Default:
            returnFactory = Singleton::Get<MapFactory>();
            break;
        case EMapType::Enchanted:
            returnFactory = Singleton::Get<EnchantedMapFactory>();
            break;
        case EMapType::Bomb:
            returnFactory = Singleton::Get<BombMapFactory>();
            break;
        case EMapType::AtomicBomb:
            returnFactory = Singleton::Get<AtomicBombMapFactory>();
            break;
        case EMapType::Lock:
            returnFactory = Singleton::Get<LockMapFactory>();
            break;
        default:
            returnFactory = nullptr;
    }

    return returnFactory;
}

FString UMapTypeProcessor::ToString(EMapType inputMapType) {
    FString returnString{""};

    switch(inputMapType) {
        case EMapType::Default:
            returnString = "Default";
            break;
        case EMapType::Enchanted:
            returnString = "Enchanted";
            break;
        case EMapType::Bomb:
            returnString = "Bomb";
            break;
        case EMapType::AtomicBomb:
            returnString = "Atomic Bomb";
            break;
        case EMapType::Lock:
            returnString = "Lock";
            break;
        default:
            returnString = "Unknown map type";
    }

    return returnString;
}

EMapType UMapTypeProcessor::FromString(FString inputString) {
    EMapType mapType{ EMapType::Default };

    if(inputString == "default") {
        mapType = EMapType::Default;
    } else if(inputString == "enchanted") {
        mapType = EMapType::Enchanted;
    } else if(inputString == "bomb") {
        mapType = EMapType::Bomb;
    } else if(inputString == "atomic bomb") {
        mapType = EMapType::AtomicBomb;
    } else if(inputString == "lock") {
        mapType = EMapType::Lock;
    } else {
        mapType = EMapType::NULL_ENUM;
    }
    
    return mapType;
}