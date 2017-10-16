// Fill out your copyright notice in the Description page of Project Settings.

#include "Fell_return.h"
#include "GameFramework/Actor.h"
#include "Engine.h"

#define OUT

// Sets default values for this component's properties
UFell_return::UFell_return()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFell_return::BeginPlay()
{
	Super::BeginPlay();

	
	
}


// Called every frame
void UFell_return::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	Volume->GetOverlappingActors(OUT Overlapping_actors);


	for (const auto* Actors : Overlapping_actors)
	{
		if (Actors->GetName() == GetWorld()->GetFirstPlayerController()->GetPawn()->GetName())
		{
			FVector Object_location = GetOwner()->GetActorLocation();
			Object_location.Z += Start_height;
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(Object_location);
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "You Fell down Try again");
		}
	}
	
}

