// Fill out your copyright notice in the Description page of Project Settings.


#include "Plate.h"

// Sets default values
APlate::APlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);



	StaticMeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//MoveDistance = (0.0f, 0.0f, 0.0f);

	
}

// Called when the game starts or when spawned
void APlate::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

}

// Called every frame
void APlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	float MoveStep = MoveSpeed * DeltaTime * MoveSign;
	CurrentLocation += MoveDirection * MoveStep;

	TraveledDistance += FMath::Abs(MoveStep);

	if (TraveledDistance >= MoveDistance)
	{
		float OverTravel = TraveledDistance - MoveDistance;
		CurrentLocation -= MoveDirection * MoveSign * OverTravel;

		MoveSign *= -1;
		TraveledDistance = 0.f;

	}

	SetActorLocation(CurrentLocation);
}

