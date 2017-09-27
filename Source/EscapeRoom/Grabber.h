// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void FindInputComponent();

	void FindPhysicsComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

private:

	UPROPERTY(EditAnyWhere)
	//how Far ahead of the player can we reach in cm
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandler = nullptr; 
	UInputComponent* InputComponent = nullptr;
	
    // Ray-Cast and Grab whats in Reach
	void Grab();
	//Colled when Grab is Released
	void Release();
	//Return the Corent point of reach line/ player Point of View
	FVector GetReachLineEnd();
	//Get the Startplayer View Point
	FVector GetReachLineStart();
	//returns hi for first physic body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
};
