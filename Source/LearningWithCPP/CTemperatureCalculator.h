// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CTemperatureCalculator.generated.h"

UCLASS(Blueprintable)
class LEARNINGWITHCPP_API UCTemperatureCalculator : public UObject
{
	GENERATED_BODY()

public:
	UCTemperatureCalculator();

	UFUNCTION(BlueprintCallable) FText Calculate(FText inputValue, FText inputUnit);

	//int32 testValue;

};
