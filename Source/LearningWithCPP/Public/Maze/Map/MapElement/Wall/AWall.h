#pragma once

#include "../AMapSite.h"

#include "AWall.generated.h"

// Defines a AWall to be put into a Map
UCLASS(BlueprintType)
class LEARNINGWITHCPP_API AWall: public AMapSite {
    GENERATED_BODY()
	
    public:
        AWall();
        void Initialize();

		virtual AMapSite* Enter();

		// Physical representation
		UPROPERTY()
		USceneComponent* root;
		UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;
};