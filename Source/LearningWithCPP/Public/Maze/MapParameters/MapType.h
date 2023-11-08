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
//      enum EMapType
//      ToMapFactory()
//      StringToMapType()
//      operator std::string()

UENUM(BlueprintType)
enum EMapType : uint8 {
    NULL_ENUM,

    Default,
    Bomb,
    AtomicBomb,
    Enchanted,
    Lock
};

// A complex enumeration that specifies a type of map
UCLASS(BlueprintType)
class LEARNINGWITHCPP_API UMapTypeProcessor : public UObject {
    GENERATED_BODY()

    public:
        // Returns the MapFactory the given EMapType represents
        static MapFactory* ToMapFactory(EMapType inputMapType);
        // Returns the string the given EMapType represents
        UFUNCTION(BlueprintCallable, BlueprintPure)
        static FString ToString(EMapType inputMapType);

        // Returns the EMapType the given string represents
        UFUNCTION(BlueprintCallable, BlueprintPure)
        static EMapType FromString(FString inputString);
};

// A bit of credit from this is owed to Kered13 from https://www.reddit.com/r/cpp/comments/zw59lh/enums_with_methods/