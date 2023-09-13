// Fill out your copyright notice in the Description page of Project Settings.


#include "Animals/CAnimalFactory.h"

#include "CAnimalT.h"
#include "Animals/CAnimalBase.h"

UCAnimalFactory::UCAnimalFactory()
{
}

UCAnimalFactory::~UCAnimalFactory()
{
}

ACAnimalBase* UCAnimalFactory::SpawnAnimal(CAnimalT animalType, FTransform transform)
{
	FActorSpawnParameters SpawnParams;
	ACAnimalBase* animal = GetWorld()->SpawnActor<ACAnimalBase>(transform.GetLocation(), transform.GetRotation().Rotator(), SpawnParams);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Spawned"));

	//animal.Action();
	
	// Note: Apparently, new cannot be used on UObjects as follows:
	// ACAnimalBase* animal = new ACAnimalBase();
	// 
	// And this causes Unreal to crash:
	// ACAnimalBase animal;

	return animal;
}