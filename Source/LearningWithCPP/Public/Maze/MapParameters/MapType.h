#pragma once

#include "../Singleton/Singleton.h"
#include "../Map/MapFactory/MapFactory.h"
#include "../Map/MapFactory/BombMapFactory/BombMapFactory.h"
#include "../Map/MapFactory/BombMapFactory/AtomicBombMapFactory/AtomicBombMapFactory.h"
#include "../Map/MapFactory/EnchantedMapFactory/EnchantedMapFactory.h"
#include "../Map/MapFactory/LockMapFactory/LockMapFactory.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MapType.generated.h"

// Anytime a new MapFactory is added, it must be added to:
//      this file's #include
//      enum MapTypeEnum
//      ToMapFactory()
//      StringToMapType()
//      operator std::string()

// A complex enumeration that specifies a type of map
USTRUCT(BlueprintType)
struct FMapType {
    GENERATED_BODY()

    public:
        enum MapTypeEnum {
            NULL_ENUM,

            Default,
            Bomb,
            AtomicBomb,
            Enchanted,
            Lock
        };

        FMapType() {};
        FMapType(MapTypeEnum input): enumVal(input) {};

        // Allows comparison with MapTypeEnum constants
        operator MapTypeEnum() const;

        // Returns the corresponding MapFactory
        MapFactory* ToMapFactory() const;

        // Sets this enum to the passed in string (if valid)
        FMapType StringToMapType(FString inputString);
        // Returns the string this enum represents
        FString GetString() const;

    private:
        MapTypeEnum enumVal{MapTypeEnum::Default};
};

// A bit of credit from this is owed to Kered13 from https://www.reddit.com/r/cpp/comments/zw59lh/enums_with_methods/