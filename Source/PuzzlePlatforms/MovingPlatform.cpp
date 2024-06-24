// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += FVector(PlatformSpeedOfX * DeltaTime, 0, 0);
		SetActorLocation(CurrentLocation);
	}
}
