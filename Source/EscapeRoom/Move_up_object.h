// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Move_up_object.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UMove_up_object : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMove_up_object();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	//function to get the object that collape with the volume
    bool Get_overlapping_actor();

	//move object up ! 
	void Move_object_up();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private: 

	//Set the Trigger volume 

	UPROPERTY(EditAnyWhere)
	ATriggerVolume*	PressurePlate;
	
	//saves all the actors in the arry 
	TArray<AActor*> Overlapping_actors;
	
	bool Actor_overlapping = false;

	FVector O_location;
};
