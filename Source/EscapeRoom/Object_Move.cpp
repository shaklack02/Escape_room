// Fill out your copyright notice in the Description page of Project Settings.

#include "Object_Move.h"
#include "Engine.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UObject_Move::UObject_Move()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UObject_Move::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	
	G_Location1 = Owner->GetActorLocation().ToString();
    
	UE_LOG(LogTemp, Warning, TEXT("%s"), *G_Location1);
	
	G_Location = FVector(Owner->GetActorLocation());

	
	Value = 24.f;
}


// Called every frame
void UObject_Move::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

//	G_Location.Set.X= 2.f;
	/*
	if (Value < 500)
	{
		Value = Value + DeltaTime + Speed;
		G_Location[2] = FMath::Asin(DeltaTime);
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *G_Location.ToString());
		Owner->SetActorLocation(G_Location);
	}
	*/
	
}

