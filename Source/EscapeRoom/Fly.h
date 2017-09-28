// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Fly.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UFly : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFly();

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnyWhere)
		int32 speed = 500;
	
	UFUNCTION()
	void onTimeEnd_First();

	UFUNCTION()
	void onTimeEnd_2();


private:

	AActor* Owner = GetOwner();

	int32 time= 6.f;

	FVector Ship_StartLocation;

	FRotator Ship_Rotation = FRotator(0.f, 0.f, 0.f);

	FVector Ship_NewLocation = FVector(0.f, 0.f, 0.f);

	FTimerHandle _LoopTimerHandle;

};
