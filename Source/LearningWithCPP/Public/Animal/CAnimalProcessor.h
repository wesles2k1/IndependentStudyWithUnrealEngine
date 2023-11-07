// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CAnimalT.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CAnimalProcessor.generated.h"

UCLASS(Blueprintable)
class LEARNINGWITHCPP_API UCAnimalProcessor : public UObject
{
	GENERATED_BODY()

public:
	UCAnimalProcessor();

	UFUNCTION(BlueprintCallable)
	CAnimalT Increment(UPARAM(ref) CAnimalT& animal);

	UFUNCTION(BlueprintCallable)
	CAnimalT Decrement(UPARAM(ref) CAnimalT& animal);

	UFUNCTION(BlueprintCallable)
	FString ToString(CAnimalT animal);

	UFUNCTION(BlueprintCallable)
	FString Action(CAnimalT animal);

};
