#pragma once

#include "../Room/ARoom.h"

#include "ADoor.generated.h"

// Defines a ADoor to be put into a Map
UCLASS(BlueprintType)
class LEARNINGWITHCPP_API ADoor: public AMapSite {
    GENERATED_BODY()
    
    public:
        ADoor();
        void Initialize(ARoom* newRoom1 = nullptr, ARoom* newRoom2 = nullptr);
        
        virtual AMapSite* Enter();
        ARoom* OtherSideFrom(ARoom*);

        // Physical representation
        UPROPERTY()
        USceneComponent* root;
        UPROPERTY(EditAnywhere)
        UStaticMeshComponent* mesh;

    protected:
        ARoom* room1{nullptr};
        ARoom* room2{nullptr};
        bool isOpen{false};
};