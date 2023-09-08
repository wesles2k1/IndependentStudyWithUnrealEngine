// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CAnimalT.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CAnimalSelector.generated.h"

UCLASS(Blueprintable)
class LEARNINGWITHCPP_API UCAnimalSelector : public UObject
{
	GENERATED_BODY()

public:
	UCAnimalSelector();

	UFUNCTION(BlueprintCallable)
	CAnimalT Increment(CAnimalT animal);

	UFUNCTION(BlueprintCallable)
	FString Stringify(CAnimalT animal);

	UFUNCTION(BlueprintCallable)
	FString Action(CAnimalT animal);

};
