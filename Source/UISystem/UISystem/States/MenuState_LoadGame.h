// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UISystem/States/MenuStateBase.h"

#include "MenuState_LoadGame.generated.h"

/**
 * 
 */

UCLASS()
class UISYSTEM_API UMenuState_LoadGame : public UMenuStateBase
{
	GENERATED_BODY()
	
	friend class UMenuStateFactory;
public:

	virtual UMenuStateBase* HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget) override;
	virtual void Enter(UMenuStateBase* _PreviousState) override;

private:
	void DrawSavedGame(FString PathToFile, FString NameToDraw, int Index);
	void LoadGame(FString SavedGameToLoad);
protected:
	UPROPERTY()
	UMenuStateBase* PreviousState = nullptr;
};
