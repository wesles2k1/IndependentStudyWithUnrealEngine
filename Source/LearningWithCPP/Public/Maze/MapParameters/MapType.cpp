#include "MapType.h"

// ------ //
// Public //
// ------ //

FMapType::operator MapTypeEnum() const {
    return enumVal;
}

MapFactory* FMapType::ToMapFactory() const {
    MapFactory* returnFactory;

    switch(enumVal) {
        case MapTypeEnum::Default:
            returnFactory = Singleton::Get<MapFactory>();
            break;
        case MapTypeEnum::Enchanted:
            returnFactory = Singleton::Get<EnchantedMapFactory>();
            break;
        case MapTypeEnum::Bomb:
            returnFactory = Singleton::Get<BombMapFactory>();
            break;
        case MapTypeEnum::AtomicBomb:
            returnFactory = Singleton::Get<AtomicBombMapFactory>();
            break;
        case MapTypeEnum::Lock:
            returnFactory = Singleton::Get<LockMapFactory>();
            break;
        default:
            returnFactory = nullptr;
    }

    return returnFactory;
}

FMapType FMapType::StringToMapType(FString inputString) {
    //std::transform(inputString.begin(), inputString.end(), inputString.begin(), [](unsigned char c){return std::tolower(c);});

    if(inputString == "default") {
        *this = FMapType::Default;
    } else if(inputString == "enchanted") {
        *this = FMapType::Enchanted;
    } else if(inputString == "bomb") {
        *this = FMapType::Bomb;
    } else if(inputString == "atomic bomb") {
        *this = FMapType::AtomicBomb;
    } else if(inputString == "lock") {
        *this = FMapType::Lock;
    } else {
        *this = FMapType::NULL_ENUM;
    }
    
    return *this;
}

FString FMapType::GetString() const {
    FString returnString{""};

    switch(enumVal) {
        case MapTypeEnum::Default:
            returnString = "Default";
            break;
        case MapTypeEnum::Enchanted:
            returnString = "Enchanted";
            break;
        case MapTypeEnum::Bomb:
            returnString = "Bomb";
            break;
        case MapTypeEnum::AtomicBomb:
            returnString = "Atomic Bomb";
            break;
        case MapTypeEnum::Lock:
            returnString = "Lock";
            break;
        default:
            returnString = "Unknown map type";
    }

    return returnString;
}