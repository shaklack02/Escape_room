// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Jump_limit.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UJump_limit : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UJump_limit();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:	
	
	FString World_name;
	FString Object_name;
	FString Player_location;
	FVector Player_vector_location;

	UPROPERTY(EditAnyWhere)
		bool Limit_jump = false;

	UPROPERTY(EditAnyWhere)
		FVector Max_jumph_hight = FVector(0, 0, 350);
	
};
