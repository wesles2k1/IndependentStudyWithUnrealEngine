// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CAnimalT.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CAnimalBase.generated.h"

UCLASS()
class LEARNINGWITHCPP_API ACAnimalBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACAnimalBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	CAnimalT animalType{ CAnimalT::DEFAULT };

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
