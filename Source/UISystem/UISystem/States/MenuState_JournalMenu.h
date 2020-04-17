// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UISystem/States/MenuStateBase.h"
#include "MenuState_JournalMenu.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API UMenuState_JournalMenu : public UMenuStateBase
{
	GENERATED_BODY()
	friend class UMenuStateFactory;
public:
	virtual UMenuStateBase* HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget) override;
	virtual void Enter(UMenuStateBase* _PreviousState) override;
};
