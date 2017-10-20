// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine.h"
#include "GameFramework/Actor.h"

#define OUT //Marker


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	//
	UE_LOG(LogTemp, Warning, TEXT("Grabber Reporting for duty! ! ! ! ! !"));	
	//Look For attached Physics Handle
	FindPhysicsComponent();
	FindInputComponent();


}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsHandler) { UE_LOG(LogTemp, Error, TEXT("PhysicsHandler MIssing")); return; }
	//if the Physics handle is Attached
	if (PhysicsHandler->GrabbedComponent)
	{
		//move the object that we're holding
		PhysicsHandler->SetTargetLocation(GetReachLineEnd());
	}
}

//finding the ingputcomponent Seting up the Inputs
void UGrabber::FindInputComponent()
{
	if (!PhysicsHandler) { UE_LOG(LogTemp, Error, TEXT("PhysicsHandler MIssing")); return; }
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (PhysicsHandler)
	{
		// Bind the Input Action
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s MISSING Physics handle component"), *GetOwner()->GetName());
	}
}
//Finding the Physics component 
void UGrabber::FindPhysicsComponent()
{

	//looking for the componnect By Class - (UPhysicsHandleComponent) once its found then Assign the Component to the PhisicsHandler pointer
	PhysicsHandler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	//Check if the Component Loaded if Physics == Null(nathing) then the Componenct now loaded and you will get Error
	if (PhysicsHandler == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s MISSING Physics handle component"), *GetOwner()->GetName());
	}
}
//return hit for first physics body in reach
const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	///Get the player View Point this tick 

	/*UE_LOG(LogTemp, Warning, TEXT("R: %s | L: %s"),S
	*PlayerViewPointLocation.ToString(),
	*PlayerViewPointRotation.ToString()
	);*/

	///Draw a REd Trace in the world to visualise
	/*
	DrawDebugLine(GetWorld(),
	PlayerViewPointLocation,
	LineTraceEnd,
	FColor(255,0,0),
	false,
	0.f,
	0.f,
	5.f
	);
	*/

	///SetUp Query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	///Ray-Cast (check where the player loocking)
	FHitResult HitResoult;
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResoult, //if hited geting the Answear here 
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	///See what we Hit
	/*AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit; %s"), *(ActorHit->GetName()));
	}*/

	return HitResoult;
}
//Grabig the hited object
void UGrabber::Grab() {
	if (!PhysicsHandler) { UE_LOG(LogTemp, Error, TEXT("PhysicsHandler MIssing")); return; }
	UE_LOG(LogTemp, Warning, TEXT("Grab Pressed"));

	//LINE TRACE and see if we Reach any actors with physics body collision channel set
	auto HitResoult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResoult.GetComponent(); //Gerts the Mesh in our case / the Mesh that we are moving
	auto ActorHit = HitResoult.GetActor();

	//If we hit soemthing then attach a physics handle 
	if (ActorHit) {
		// attach physics handle
		PhysicsHandler->GrabComponent(
			ComponentToGrab, //component turn out to be a mesh ... no idea what its doing 
			NAME_None, //no bones needed 
			ComponentToGrab->GetOwner()->GetActorLocation(), // Where we are Grabing the Object ( to player location)
			true); // allow rotation
	}
}
//Releasing it 
void UGrabber::Release() {

	if (!PhysicsHandler) { UE_LOG(LogTemp, Error, TEXT("PhysicsHandler  MIssing")); return; }
	UE_LOG(LogTemp, Warning, TEXT("Grab Released"));

	//release physics handle
	PhysicsHandler->ReleaseComponent();
}

FVector  UGrabber::GetReachLineEnd() {

	//Get the Player View Point Every Tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;


}

FVector  UGrabber::GetReachLineStart() {

	//Get the Player View Point Every Tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation;


}
