// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaGameModeBase.h"
#include "Homework7/SpartaPawnSystem.h"
#include "Homework7/SpartaPlayerController.h"
ASpartaGameModeBase::ASpartaGameModeBase()
{

	DefaultPawnClass = ASpartaPawnSystem::StaticClass();
	PlayerControllerClass = ASpartaPlayerController::StaticClass();
}
