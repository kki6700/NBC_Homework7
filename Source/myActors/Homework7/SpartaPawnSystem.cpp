// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaPawnSystem.h"
#include "Components/CapsuleComponent.h"
#include "SpartaPlayerController.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/SkeletalMesh.h"
// Sets default values
ASpartaPawnSystem::ASpartaPawnSystem()
{
	CapsuleColliderComp = CreateDefaultSubobject< UCapsuleComponent>(TEXT("CapSuleCollider"));
	SetRootComponent(CapsuleColliderComp);
	CapsuleColliderComp->SetCapsuleHalfHeight(95.0f);
	CapsuleColliderComp->SetCapsuleRadius(37.0f);


	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComponent->SetupAttachment(CapsuleColliderComp);
	SpringArmComponent->TargetArmLength = 300.0f;
	SpringArmComponent->bUsePawnControlRotation = true;


	

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComponent);
	CameraComp->bUsePawnControlRotation = false;
 	

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
	SkeletalMeshComp->SetupAttachment(CapsuleColliderComp);
	SkeletalMeshComp->SetSimulatePhysics(false);
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Resources/Characters/Meshes/SKM_Manny.SKM_Manny"));

	if (MeshAsset.Succeeded())
	{
		SkeletalMeshComp->SetSkeletalMesh(MeshAsset.Object);
	}
	SkeletalMeshComp->SetRelativeLocation(FVector(0.f, 0.f, -90.0f));
	SkeletalMeshComp->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f ));
	MoveSpeed = 400.f;
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}



// Called to bind functionality to input
void ASpartaPawnSystem::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ASpartaPlayerController* PlayerController = Cast <ASpartaPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					& ASpartaPawnSystem::Move
				);
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Completed, this, &ASpartaPawnSystem::StopMove);
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaPawnSystem::Look
				);
			}
			
		}
	}

}
void ASpartaPawnSystem::Move(const FInputActionValue& value)
{
	MovementInput = value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("Move() 호출됨!"));
}

void ASpartaPawnSystem::Look(const FInputActionValue& value)
{
	LookInput = value.Get<FVector2D>();

	// 마우스 감도 (원하는 값으로 조정)
	float YawSensitivity = 1.5f;
	float PitchSensitivity = 1.2f;

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		// Yaw(좌우) - 마우스 X
		PC->AddYawInput(LookInput.X * YawSensitivity);

		// Pitch(상하) - 마우스 Y (일반적으로 마우스 Y는 반전)
		PC->AddPitchInput(LookInput.Y * PitchSensitivity);
	}
}

void ASpartaPawnSystem::StopMove(const FInputActionValue& value)
{
	MovementInput = FVector2D::ZeroVector;
}

void ASpartaPawnSystem::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
	Super::Tick(DeltaTime);

	// MovementInput은 FVector2D나 FVector로 입력받은 값
	// 카메라 기준 방향
	if (!MovementInput.IsNearlyZero())
	{
		FVector Forward = CameraComp->GetForwardVector();
		FVector Right = CameraComp->GetRightVector();
		FVector MoveDirection = Forward * MovementInput.X + Right * MovementInput.Y;
		MoveDirection.Z = 0.f;
		MoveDirection.Normalize();

		AddActorWorldOffset(MoveDirection * MoveSpeed * DeltaTime, true);



		if (!MoveDirection.IsNearlyZero())
		{
			FRotator TargetRot = MoveDirection.Rotation();
			TargetRot.Pitch = 0.f;
			TargetRot.Roll = 0.f;
			FRotator NewRot = FMath::RInterpTo(GetActorRotation(), TargetRot, DeltaTime, 10.f); // 부드럽게
			SetActorRotation(NewRot);
		}

	}
	
}



