// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "TextBlock.h"

#include "Engine.h"
#include "UISystem/States/MenuStateBase.h"

#include "MenuState_MainMenu.generated.h"

class UMenuState_LoadGame;
/**
 * 
 */


UCLASS()
class UISYSTEM_API UMenuState_MainMenu : public UMenuStateBase
{
	GENERATED_BODY()
	
	friend class UMenuStateFactory;
public:

	virtual UMenuStateBase* HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget) override;
	virtual void Enter() override;
	virtual void Exit() override;
	
};
