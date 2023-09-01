// Fill out your copyright notice in the Description page of Project Settings.


#include "CGorkaCharacter.h"

// Sets default values
ACGorkaCharacter::ACGorkaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACGorkaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACGorkaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACGorkaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Spawns specified actor at specified location
void ACGorkaCharacter::SpawnActor()
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(actorBPToSpawn, spawnTransform, spawnParams);
}

