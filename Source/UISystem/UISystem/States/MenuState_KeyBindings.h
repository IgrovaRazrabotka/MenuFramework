// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UISystem/States/MenuStateBase.h"

#include "MenuState_KeyBindings.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API UMenuState_KeyBindings : public UMenuStateBase
{
	GENERATED_BODY()

	friend class UMenuStateFactory;
public:

	virtual UMenuStateBase* HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget) override;
	virtual void Enter(UMenuStateBase* _PreviousState) override;
	virtual void Exit() override;
	
};
