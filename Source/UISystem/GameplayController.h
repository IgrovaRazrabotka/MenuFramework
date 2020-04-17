// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayController.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API AGameplayController : public APlayerController
{
	GENERATED_BODY()
	
	AGameplayController();
protected:

	virtual void BeginPlay() override;

	UPROPERTY()
		UClass* MenuWidgetClass;
};
