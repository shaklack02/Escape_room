// Fill out your copyright notice in the Description page of Project Settings.

#include "Jump_limit.h" 
#include "GameFramework/Actor.h"  // GetActorLocation(); wont work without it 
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

	//object_name = GetWorld()->GetName();
	//Test = GetWorld()->GetFirstPlayerController()->GetPawn();
    
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green,"Player Location:" + object_name);
	//UE_LOG(LogTemp, Warning, TEXT("Test object : %s"), *object_name);
	
}


// Called every frame
void UJump_limit::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

