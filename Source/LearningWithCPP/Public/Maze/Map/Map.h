#pragma once

#include <vector>

#include "MapFactory/MapFactory.h"
#include "MapElement/MapElementInclude.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Map.generated.h"

UCLASS(BlueprintType, Blueprintable)
class LEARNINGWITHCPP_API ATestObject : public AActor {
    GENERATED_BODY()

    public:
        ATestObject() {};
};

// Defines a Map
UCLASS(BlueprintType, Blueprintable)
class LEARNINGWITHCPP_API AMap : public AActor {
    GENERATED_BODY()

    public:
        AMap();

        void AddRoom(ARoom* newRoom);
        ARoom* GetRoom(int id) const;

        //UPROPERTY(EditAnywhere, BlueprintReadWrite)
        std::vector<ARoom*> roomStorage;
        UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray < ATestObject* > test;
        int nextRoomID{ 1 };
};