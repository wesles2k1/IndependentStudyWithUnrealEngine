// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CAnimalT.h"
#include "Animals/CAnimalBase.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CAnimalFactory.generated.h"

UCLASS(Blueprintable)
class LEARNINGWITHCPP_API UCAnimalFactory : public UObject
{
	GENERATED_BODY()

public:
	UCAnimalFactory();
	~UCAnimalFactory();

	UFUNCTION(BlueprintCallable)
	ACAnimalBase* SpawnAnimal(CAnimalT animalType, FTransform transform);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ACAnimalBase> AnimalToSpawn;
};
