// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
#include "GameFramework/Actor.h"
#include "Engine.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();
    //Set up a Delay Time 
	
	//Get the Player Location (FINALY DID IT )  !!
	Player_location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(); 
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "Object Name:" + Player_location.ToString());
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//Get the palyer Position
	Player_location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//Calculate the Vectors where the Pet will fly 
	Player_location += Flying_object_position;	

	//FString::SanitizeFloat(DeltaTime) Converting Float to FString
	/*GEngine->AddOnScreenDebugMessage(Screan_posision, 0.05f, FColor::Green,
		FString::SanitizeFloat(DeltaTime),
		true,
		Font_Scale);*/

	//Make the object Fly 
	//Make the Object Move up and down smoothly 
	float DeltaHeight = FMath::Sin(Fly_Object_const + Up_down_speed) - FMath::Sin(Fly_Object_const);
	Player_location.Z += DeltaHeight * Amplitude;
	GetOwner()->SetActorLocation(Player_location); // seeting the New location 

	GEngine->AddOnScreenDebugMessage(Screan_posision, 0.05f, FColor::Green,
		FString::SanitizeFloat(Player_location.Z), // converting the Float to string 
		true,
		Font_Scale);
	Fly_Object_const += Up_down_speed; //no idea yet what is that lol ... 

	//rotate the Object
	GetOwner()->AddActorLocalRotation(Rotation_Rate * DeltaTime * Rotation_speed); 
	

}

