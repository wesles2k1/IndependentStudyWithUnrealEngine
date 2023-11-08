#pragma once

#include "MapType.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MapOption.generated.h"

// Expresses a factory and its odds of being used
USTRUCT(BlueprintType)
struct FMapOption {
    GENERATED_BODY()

    //UPROPERTY(EditAnywhere, BlueprintReadWrite)
    MapType factory{MapType::Default};
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float odds{1.0};
};