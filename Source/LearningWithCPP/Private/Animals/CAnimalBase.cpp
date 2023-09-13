// Fill out your copyright notice in the Description page of Project Settings.


#include "Animals/CAnimalBase.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ACAnimalBase::ACAnimalBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACAnimalBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACAnimalBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACAnimalBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}