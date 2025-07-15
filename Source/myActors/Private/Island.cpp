// Fill out your copyright notice in the Description page of Project Settings.


#include "Island.h"

// Sets default values
AIsland::AIsland()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	ScenceRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ScenceRoot"));
	SetRootComponent(ScenceRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(ScenceRoot);

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AIsland::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIsland::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float RunningTime = GetWorld()->GetTimeSeconds();
	float MoveZ = FMath::Sin(RunningTime * 2.0f) * 50.0f * DeltaTime;

	FVector Offset = FVector(0.f, 0.f, MoveZ);



	AddActorWorldOffset(Offset);

}

