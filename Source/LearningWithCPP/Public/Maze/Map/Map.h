#pragma once

#include <vector>

#include "MapFactory/MapFactory.h"
#include "MapElement/MapElementInclude.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Map.generated.h"

// Defines a Map
UCLASS(BlueprintType, Blueprintable)
class LEARNINGWITHCPP_API AMap : public AActor {
    GENERATED_BODY()

    public:
        AMap();

        void AddRoom(Room* newRoom);
        Room* GetRoom(int id) const;

        //UPROPERTY(EditAnywhere, BlueprintReadWrite)
        std::vector<Room*> roomStorage;
        int nextRoomID{1};
};