// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Blue_print_C_move_up.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMove_actor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UBlue_print_C_move_up : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBlue_print_C_move_up();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Trigger();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

private:
	
	UPROPERTY(BlueprintAssignable)
	FMove_actor Move_object;

	UPROPERTY(BlueprintAssignable)
    FMove_actor Move_back_object;

	UPROPERTY(EditAnyWhere)
		ATriggerVolume* Trigger_volume = nullptr; 
		
	
};
