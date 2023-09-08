// Fill out your copyright notice in the Description page of Project Settings.


#include "CAnimalSelector.h"

#include "CAnimalT.h"

UCAnimalSelector::UCAnimalSelector()
{

}

CAnimalT UCAnimalSelector::Increment(CAnimalT animal)
{
	return animal;
}

FString UCAnimalSelector::Stringify(CAnimalT animal)
{
	return "IT_WORKED";
}

FString UCAnimalSelector::Action(CAnimalT animal)
{
	return "ACTION";
}