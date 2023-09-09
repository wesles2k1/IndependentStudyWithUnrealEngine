// Fill out your copyright notice in the Description page of Project Settings.


#include "CAnimalSelector.h"

#include "CAnimalT.h"

UCAnimalSelector::UCAnimalSelector()
{

}

CAnimalT UCAnimalSelector::Increment(CAnimalT& animal)
{
	// Works, but not particularly great when adding/rearranging CAnimalT
	switch (animal)
	{
	case CAnimalT::DOG:
		animal = CAnimalT::CAT;
		break;
	case CAnimalT::CAT:
		animal = CAnimalT::HORSE;
		break;
	case CAnimalT::HORSE:
		animal = CAnimalT::FOX;
		break;
	case CAnimalT::FOX:
		animal = CAnimalT::DOG;
		break;
	}
	
	return animal;
}

CAnimalT UCAnimalSelector::Decrement(CAnimalT& animal)
{
	// Works, but not particularly great when adding/rearranging CAnimalT
	switch (animal)
	{
	case CAnimalT::DOG:
		animal = CAnimalT::FOX;
		break;
	case CAnimalT::CAT:
		animal = CAnimalT::DOG;
		break;
	case CAnimalT::HORSE:
		animal = CAnimalT::CAT;
		break;
	case CAnimalT::FOX:
		animal = CAnimalT::HORSE;
		break;
	}

	return animal;
}

FString UCAnimalSelector::ToString(CAnimalT animal)
{
	FText textVar;

	// Originally used switch statement, but this seems better and doesn't sneed modified when new CAnimalTs are added
	// Note: In the case of no display text to give, it just gives the C++ enum identifier as a string by default
	UEnum::GetDisplayValueAsText(animal, textVar);

	return textVar.ToString();
}

FString UCAnimalSelector::Action(CAnimalT animal)
{
	FString stringVar{ "" };

	switch (animal)
	{
	case CAnimalT::DOG:
		stringVar = "Woof!";
		break;
	case CAnimalT::CAT:
		stringVar = "Meow!";
		break;
	case CAnimalT::HORSE:
		stringVar = "Neigh!";
		break;
	case CAnimalT::FOX:
		stringVar = "Ring-ding-ding-ding-dingeringeding!";
		break;
	case CAnimalT::DEFAULT:
		stringVar = "No animal selected.";
		break;
	default:
		stringVar = "Unrecognized animal.";
	}

	return stringVar;
}