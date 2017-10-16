// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Fell_return.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UFell_return : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFell_return();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<AActor*> Overlapping_actors;

	UPROPERTY(EditAnyWhere)
		ATriggerVolume* Volume;

	UPROPERTY(EditAnyWhere)
		int32 Start_height = 60;
	
};
