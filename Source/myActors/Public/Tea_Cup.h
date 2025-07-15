// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tea_Cup.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSparta, Warning, All);

UCLASS()
class MYACTORS_API ATea_Cup : public AActor
{
	GENERATED_BODY()	
	
public:	
	// Sets default values for this actor's properties
	ATea_Cup();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ATea_Cup|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATea_Cup|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	// 회전 속도를 각 축별로 디테일 패널에서 조절 가능
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATea_Cup|Properties")
	float YawSpeed = 90.f;   // 초당 Yaw(요) 회전 각도 (도/초)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATea_Cup|Properties")
	float PitchSpeed = 0.f;  // 초당 Pitch(피치) 회전 각도

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATea_Cup|Properties")
	float RollSpeed = 0.f;   // 초당 Roll(롤) 회전 각도


	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
