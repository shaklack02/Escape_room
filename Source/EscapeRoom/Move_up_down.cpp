// Fill out your copyright notice in the Description page of Project Settings.

#include "Move_up_down.h"
//#include "GameFramework/Actor.h"
#include "Engine.h"

// Sets default values for this component's properties
UMove_up_down::UMove_up_down()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UMove_up_down::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UMove_up_down::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

