#pragma once

#include "../AMapSite.h"
#include "../Direction.h"

#include "ARoom.generated.h"

// Defines a ARoom to be put into a Map
UCLASS(BlueprintType)
class LEARNINGWITHCPP_API ARoom: public AMapSite {
    GENERATED_BODY()
    
    public:
        ARoom();
        void Initialize(int newRoomID);

        AMapSite* GetSide(Direction direction);
        void SetSide(Direction direction, AMapSite* element);
        void RemoveSide(Direction direction);

        int GetID();

        virtual AMapSite* Enter();

        // Physical representation
        UPROPERTY()
        USceneComponent* root;
        UPROPERTY(EditAnywhere)
        UStaticMeshComponent* mesh;
    
    protected:
        AMapSite* sides[4];
        UPROPERTY(VisibleAnywhere)
        int roomID{-1};
};