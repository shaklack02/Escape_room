// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PositionReport.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UPositionReport : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPositionReport();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	//Called when the time is ends

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:

	FVector Player_location; // TO save the palyer location in 
	//FString Object_name; //just for testing 
	FRotator Rotation_Rate = FRotator(0.f,180.f,0.f);  // for the Rotation 180 

	UPROPERTY(EditAnyWhere)
	FVector2D Font_Scale = FVector2D(1.5f,1.5f); //font print scale 

	//UPROPERTY(EditAnyWhere)
	 int32 Screan_posision = -1; //varible for the debugmessage

	UPROPERTY(EditAnyWhere)
	FVector Flying_object_position = FVector(50.f,50.f,50.f); //onject position from the player

	UPROPERTY(EditAnyWhere)
		float Rotation_speed = 0.3f; // object rotation speed 

	UPROPERTY(EditAnyWhere)
		float Fly_Object_const = 2.0f; //just a varible for the Sin() 

	UPROPERTY(EditAnyWhere)
		float Up_down_speed = 0.06; //up and down fly speed

	UPROPERTY(EditAnyWhere)
		float Amplitude = 100; //object up and down limits fly


};
