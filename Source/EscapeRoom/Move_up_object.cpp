// Fill out your copyright notice in the Description page of Project Settings.

#include "Move_up_object.h"
#include "GameFramework/Actor.h"
#include "Engine.h"

#define OUT
// Sets default values for this component's properties
UMove_up_object::UMove_up_object()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMove_up_object::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "Test:" + GetWorld()->GetFirstPlayerController()->GetPawn()->GetName());

}


bool UMove_up_object::Get_overlapping_actor()
{


	PressurePlate->GetOverlappingActors(OUT Overlapping_actors);

	for (const auto* Actor : Overlapping_actors)
	{
		if (Actor->GetName() == GetWorld()->GetFirstPlayerController()->GetPawn()->GetName()) {
			// call a function to move the object
			Move_object_up();
			Actor_overlapping = true;
		}
	}

	return Actor_overlapping;
}

void UMove_up_object::Move_object_up()
{		
	// have to fix it  (done)
		O_location = GetOwner()->GetActorLocation();
		O_location.Z = O_location.Z + speed;
		GetOwner()->SetActorLocation(O_location);
    //GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::SanitizeFloat(O_location.Z));
	
}

// Called every frame
void UMove_up_object::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Get_overlapping_actor())
	{
		
		if (O_location.Z > Limit_Hight) {
			O_location.Z = Limit_Hight;
			Actor_overlapping = false;
			GetOwner()->SetActorLocation(O_location);
		}
		Move_object_up();

		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "Ture");
		//Actor_overlapping = false;
	}
	
}

