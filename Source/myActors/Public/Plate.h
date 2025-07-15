// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plate.generated.h"

UCLASS()
class MYACTORS_API APlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "APlate|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "APlate|Components")
	UStaticMeshComponent* StaticMeshComp;




	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "APlate|Properties")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "APlate|Properties")
	FVector MoveDirection = FVector(0.0f, 0.0f, 0.0f).GetSafeNormal();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "APlate|Properties")
	float MoveDistance = 400.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "APlate|Properties")
	float MoveSpeed = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "APlate|Properties")
	float TraveledDistance = 0.;

	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "APlate|Properties")
	int32 MoveSign = 1;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
