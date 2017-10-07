// Fill out your copyright notice in the Description page of Project Settings.

#include "Jump_limit.h" 
#include "GameFramework/Actor.h"  // GetOwner()-> wont work without it 
#include "Engine.h"  // Library to make the GetWorld() to work

// Sets default values for this component's properties
UJump_limit::UJump_limit()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJump_limit::BeginPlay()
{
	Super::BeginPlay();
	if (Limit_jump) {
		World_name = GetWorld()->GetName();
		Object_name = GetOwner()->GetName();
		Player_location = GetOwner()->GetActorLocation().ToString();
		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green,
		//	"World Name: " + 
		//	World_name + 
		//	"Object Location: " + 
		//	Player_location
		//);
		//UE_LOG(LogTemp, Warning, TEXT("Object Name : %s"), *Object_name);	
	}
}


// Called every frame
void UJump_limit::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Limit_jump) {
		Player_vector_location = GetOwner()->GetActorLocation();
		if (Player_vector_location.Z > Max_jumph_hight.Z) {
			Player_vector_location.Z = Max_jumph_hight.Z;
			GetOwner()->SetActorLocation(Player_vector_location);
			//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, Player_vector_location.ToString());
		}
	}
}

