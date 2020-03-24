// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UISystem/States/MenuStateBase.h"
#include "MenuState_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API UMenuState_SaveGame : public UMenuStateBase
{
	GENERATED_BODY()
	friend class UMenuStateFactory;
public:

	virtual UMenuStateBase* HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget) override;
	virtual void Enter() override;

private:
	void DrawSavedGame(FString PathToFile, FString NameToDraw, int Index);
	void SaveGame(FString GameToSave);
};
