// Fill out your copyright notice in the Description page of Project Settings.


#include "CLaleyActor.h"
#include "LearningWithCPPCharacter.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ACLaleyActor::ACLaleyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ValueA = 0;
	ValueB = 0;

}

// Returns value calculated from this class's integer values
int32 ACLaleyActor::CalculateValue()
{
	OnValueCalculate();
	return ValueA + ValueB;
}

// Called whenever values are calculated (the following is the default, but can be overriden in the Blueprint)
void ACLaleyActor::OnValueCalculate_Implementation()
{
	// Gets the player character and casts it to a LearningWithCPPCharacter
	ALearningWithCPPCharacter* AsLearningWithCPPCharacter = Cast<ALearningWithCPPCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (AsLearningWithCPPCharacter != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Success: Player Character is of type LearningWithCPPCharacter"));
		// The next line could be used to access the values of the player character AS a LearningWithCPPCharacter
		//AsLearningWithCPPCharacter->someBool = true;
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Failed: Player Character is not of type LearningWithCPPCharacter"));
	}
}

// Called when the game starts or when spawned
void ACLaleyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACLaleyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

