// Fill out your copyright notice in the Description page of Project Settings.


#include "Homework7/SpartaPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubSystems.h"
ASpartaPlayerController::ASpartaPlayerController()
	:InputMappingContext(nullptr),
		MoveAction(nullptr),
		JumpAction(nullptr),
		LookAction(nullptr),
		SprintAction(nullptr)
{
	ConstructorHelpers::FObjectFinder<UInputMappingContext> IMCObj(TEXT("/Game/BluePrints/PawnMappingSys.PawnMappingSys"));
	if (IMCObj.Succeeded())
	{
		InputMappingContext = IMCObj.Object;
	}
	ConstructorHelpers::FObjectFinder<UInputAction> MoveActionAsset(TEXT("/Game/BluePrints/MoveAction.MoveAction"));
	if (MoveActionAsset.Succeeded())
	{
		MoveAction = MoveActionAsset.Object;
	}
	ConstructorHelpers::FObjectFinder<UInputAction> LookActionAsset(TEXT("/Game/BluePrints/LookAction.LookAction"));
	if (LookActionAsset.Succeeded())
	{
		LookAction = LookActionAsset.Object;
	}
	
}

void ASpartaPlayerController::BeginPlay()
{

	Super::BeginPlay();
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			
			
			if (InputMappingContext) 
			{
				SubSystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}
