// Fill out your copyright notice in the Description page of Project Settings.

#include "Fly.h"
#include "Engine.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UFly::UFly()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFly::BeginPlay()
{
	Super::BeginPlay();
   
	//Owner = GetOwner();

	Ship_StartLocation = Owner->GetActorLocation();
	Ship_Rotation = Owner->GetActorRotation();

   //Ship_StartLocation.Y += 20000;
	GetWorld()->GetTimerManager().SetTimer(_LoopTimerHandle, this, &UFly::onTimeEnd_First, time, false);
}


// Called every frame
void UFly::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	

	//float Check_Cal = FMath::Pow(2.71828, DeltaTime); //FMath::Pow(A,B) Hezka A^B
	//
	//UE_LOG(LogTemp, Warning, TEXT("Ship Name = %s "), *Owner->GetName());
	//UE_LOG(LogTemp, Warning, TEXT("x = %s "), *Ship_StartLocation.ToString()); // CONVERTING float to string>>> FString::SanitizeFloat(Check_Cal)

	Ship_StartLocation.Y = Ship_StartLocation.Y + DeltaTime * speed;
	//UE_LOG(LogTemp, Warning, TEXT("Y = %s "), *FString::SanitizeFloat(Ship_NewLocation.Y));
	Owner->SetActorLocation(Ship_StartLocation);
}


void UFly::onTimeEnd_First() {
	Ship_StartLocation.Y += ShipDistance;
	time = 3;
	GetWorld()->GetTimerManager().SetTimer(_LoopTimerHandle, this, &UFly::onTimeEnd_2, time, false);
}

void UFly::onTimeEnd_2()
{
	
	for (float var = 0.5; var <= 90; var++)
	{
		Ship_Rotation.Roll = Ship_Rotation.Roll + var * speed;
		UE_LOG(LogTemp, Warning, TEXT("%%%%%% "));
	}
}