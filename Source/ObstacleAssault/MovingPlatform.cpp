// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	//MyX = MyVector.X;
	//MyVector.Z = MyX;
	StartLocation = GetActorLocation();

	
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//NOTES:
	// FVector LocalVector = MyVector;
	// LocalVector.Z = LocalVector.Z + 1;
	// MyVector.Y = MyVector.Y + 1;
	// SetActorLocation(LocalVector);

	//Move platform forward
		//get current location
	FVector CurrentLocation = GetActorLocation();
		//add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		//set the location
	SetActorLocation(CurrentLocation);
	//Send platform back if gone too far
		//check how far we've moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		//reverse direction of motion if gone too far
	if (DistanceMoved > MovedDistance)
	{
		// PlatformVelocity *= -1;
		// StartLocation = CurrentLocation;

		//Fixes bugs regarding drifting
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MovedDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}

}

