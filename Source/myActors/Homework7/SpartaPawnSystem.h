// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpartaPawnSystem.generated.h"


class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;


UCLASS()
class MYACTORS_API ASpartaPawnSystem : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpartaPawnSystem();



public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterComponents")
	UCapsuleComponent* CapsuleColliderComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterComponents")
	USkeletalMeshComponent* SkeletalMeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterComponents")
	UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterComponents")
	USpringArmComponent* SpringArmComponent;
//protected:
	FVector2D MovementInput;
	FVector2D LookInput;
	float MoveSpeed;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	//virtual void Tick(float Deltatime) override;
	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);

	void StopMove(const FInputActionValue& value);
};
