// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UISystem/States/MenuStateBase.h"

#include "MenuState_ContinueGame.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API UMenuState_ContinueGame : public UMenuStateBase
{
	GENERATED_BODY()
	
	friend class UMenuStateFactory;
public:
	virtual void Enter() override;
};
