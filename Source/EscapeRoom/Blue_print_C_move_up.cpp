// Fill out your copyright notice in the Description page of Project Settings.

#include "Blue_print_C_move_up.h"
#include "Components/ActorComponent.h"
#include "Engine.h"

// Sets default values for this component's properties
UBlue_print_C_move_up::UBlue_print_C_move_up()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBlue_print_C_move_up::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UBlue_print_C_move_up::Trigger()
{
	//checking if there is a volume if not error mesage 
	if (!Trigger_volume) { GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, "Trigger missing"); return; }
	//checking if the actor is overloping the trigger volume
	if (Trigger_volume->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{
		Move_object.Broadcast(); // event for Blueprint to move the object
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, "Move up"); 
	}
	else
	{
		Move_back_object.Broadcast(); // event for blueprint to move the object
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, "Move back");
	}
}

// Called every frame
void UBlue_print_C_move_up::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//calling the trigger function
	Trigger();
}


