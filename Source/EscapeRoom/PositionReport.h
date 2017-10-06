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

	FVector Player_location;
	FString Object_name;

	FRotator Rotation_Rate = FRotator(0.f, 180, 0.f);
	FTimerHandle _LoopTimerHandle;

	UPROPERTY(EditAnyWhere)
	FVector Flying_object_position = FVector(50.f,50.f,50.f);

	UPROPERTY(EditAnyWhere)
		float Rotation_speed = 0.3;
	UPROPERTY(EditAnyWhere)
		float Fly_Object_const = 2;

};
