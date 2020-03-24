// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UISystem/States/MenuStateBase.h"
#include "MenuState_QuitToMenu.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API UMenuState_QuitToMenu : public UMenuStateBase
{
	GENERATED_BODY()
	friend class UMenuStateFactory;
public:

	virtual UMenuStateBase* HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget) override;
	virtual void Enter() override;
};
