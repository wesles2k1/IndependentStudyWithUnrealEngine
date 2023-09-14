// Fill out your copyright notice in the Description page of Project Settings.


#include "Animals/CAnimalFactory.h"

#include "CAnimalT.h"
#include "Animals/CAnimalBase.h"
#include "Animals/CDog.h"
#include "Animals/CCat.h"
#include "Animals/CHorse.h"
#include "Animals/CFox.h"
#include "Animals/CChicken.h"

UCAnimalFactory::UCAnimalFactory()
{
}

UCAnimalFactory::~UCAnimalFactory()
{
}

ACAnimalBase* UCAnimalFactory::SpawnAnimal(CAnimalT animalType, FTransform transform)
{
	FActorSpawnParameters SpawnParams;

	ACAnimalBase* animal{ nullptr };
	// Is there a better way to do this than a switch?
	// I'm not sure I'm aware of how I can generically specify a type to spawn at the moment. This would be a pain to keep up with if the enumeration is to be expandable.
	// Additionally, file inclusion is kind of ugly
	switch (animalType)
	{
	case CAnimalT::DOG:
		animal = GetWorld()->SpawnActor<ACDog>(transform.GetLocation(), transform.GetRotation().Rotator(), SpawnParams);
		break;
	case CAnimalT::CAT:
		animal = GetWorld()->SpawnActor<ACCat>(transform.GetLocation(), transform.GetRotation().Rotator(), SpawnParams);
		break;
	case CAnimalT::HORSE:
		animal = GetWorld()->SpawnActor<ACHorse>(transform.GetLocation(), transform.GetRotation().Rotator(), SpawnParams);
		break;
	case CAnimalT::FOX:
		animal = GetWorld()->SpawnActor<ACFox>(transform.GetLocation(), transform.GetRotation().Rotator(), SpawnParams);
		break;
	case CAnimalT::CHICKEN:
		animal = GetWorld()->SpawnActor<ACChicken>(transform.GetLocation(), transform.GetRotation().Rotator(), SpawnParams);
		break;
	}
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Spawned"));

	
	// Note: Apparently, new cannot be used on UObjects as follows:
	// ACAnimalBase* animal = new ACAnimalBase();
	// 
	// And this causes Unreal to crash:
	// ACAnimalBase animal;

	return animal;
}