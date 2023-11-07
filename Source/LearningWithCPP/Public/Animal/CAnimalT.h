// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class CAnimalT : uint8
{
	DEFAULT	UMETA(DisplayName = "None"),

	DOG		UMETA(DisplayName = "Dog"),
	CAT		UMETA(DisplayName = "Cat"),
	HORSE	UMETA(DisplayName = "Horse"),
	FOX		UMETA(DisplayName = "Fox"),
	CHICKEN	UMETA(DisplayName = "Chicken")
};