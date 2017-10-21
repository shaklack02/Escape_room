// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	//ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn(); 
	Owner = GetOwner();
}




// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// Poll the Trigger Volume
	// if the ActorThatOpens is in the Volume 
	//if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	
	if (GetTotalMassOfActorOnPlate() > Trigger_mass)
	{
		On_open.Broadcast(); //request to enter in to a blueprint 
	
		//OpenTheDoor();
		//LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	
	//if (GetWorld()->GetTimeSeconds()-LastDoorOpenTime > DoorCloseDelay)
	else
	{
		On_close.Broadcast();
		//trigget for blueprint
		//CloseTheDoor();
	}
}

////void UOpenDoor::OpenTheDoor()
//{
//	// Creat a rotator
//	//FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f); //
//	//UE_LOG(LogTemp, Warning, TEXT("Open"));
//	// Set the door rotation
//	//Owner->SetActorRotation(NewRotation);
// //On_open_request.Broadcast(); //request to enter in to a blueprint 
//}
//
////void UOpenDoor::CloseTheDoor()
//{
//	// Creat a rotator
//	//FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f); //
//	//UE_LOG(LogTemp, Warning, TEXT("Closed"));	
//	// Set the door rotation
//	//Owner->SetActorRotation(NewRotation);
//
//	
//}

float UOpenDoor::GetTotalMassOfActorOnPlate()
{
	float TotalMass = 0.f;
	if (!PressurePlate) { UE_LOG(LogTemp, Warning, TEXT("pressurePlate missing")); return TotalMass; } // protecting From crashing if the Plate not existing
	FString X;
	TArray<AActor*> OverlapingActors;
	//Find all the overlapping actors
	PressurePlate->GetOverlappingActors(OUT OverlapingActors);
	//Iterate through them adding their masses
	for (const auto* Actor : OverlapingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		//Actor->FindComponentByClass<UPrimitiveComponent>()->GetName(); // Mass is a UPrimitiveComponent class !!
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure Plate"), *Actor->GetName());
	   /*  X = FString::SanitizeFloat(TotalMass);
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure Plate"), *X);*/
	}
	
	return TotalMass;
}