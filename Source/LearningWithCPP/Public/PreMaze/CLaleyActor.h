// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLaleyActor.generated.h"

UCLASS()
class LEARNINGWITHCPP_API ACLaleyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACLaleyActor();

	// Two integer values editable by within the Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestValues") int32 ValueA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestValues") int32 ValueB;

	// Returns value calculated from this class's integer values
	UFUNCTION(BlueprintCallable, Category = "TestFunctions") int32 CalculateValue();

	// Called whenever values are calculated
	UFUNCTION(BlueprintNativeEvent, Category = "TestFunctions") void OnValueCalculate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
