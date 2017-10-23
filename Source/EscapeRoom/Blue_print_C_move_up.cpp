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

	if (!Trigger_volume) { GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, "TriggerColume missing"); return; }

	if (Trigger_volume->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetOwner()))
		Move_object.Broadcast();
	else
		Move_back_object.Broadcast();


}




// Called every frame
void UBlue_print_C_move_up::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//TODO First The Trigger() seems liek its not Reading it right in the blueprint
	Trigger();
}



