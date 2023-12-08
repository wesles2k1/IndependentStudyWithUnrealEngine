#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMapSite.generated.h"

// Defines a component of the map/part of the room
UCLASS(BlueprintType, Blueprintable)
class LEARNINGWITHCPP_API AMapSite : public AActor {
	GENERATED_BODY()
	
    public:
        virtual ~AMapSite() = default;
        virtual AMapSite* Enter() {return nullptr;};
};