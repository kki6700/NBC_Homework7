// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Island.generated.h"

UCLASS()
class MYACTORS_API AIsland : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIsland();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Island|Components")
	USceneComponent* ScenceRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Island|Components")
	UStaticMeshComponent* StaticMeshComp;

	FRotator Se = FRotator(0.f, 0.f, 0.f);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
