// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "UISystem/States/MenuStateFactory.h"
#include "UISystem/States/MenuMemory.h"

#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
		virtual void Init() override;


public:

	AGameStateBase* GetGameStateBase();
	APlayerController* GetPlayerController();
	UMenuStateFactory* GetMenuStateFactory();
	UMenuMemory* GetMenuMemory();
	FString GetLatestSavedGameFilePath();

	FString SavedGamesPath;
	FString IniFilePath;
	FString NullSavedGame;

	TMap<ESavedGame, FString> SavedGamesNames;
	TMap<ESavedGame, FString> SavedGamesPaths;

protected:

	UPROPERTY()
	UMenuStateFactory* MenuStateFactory = nullptr;
	UPROPERTY()
	UMenuMemory* MenuMemory = nullptr;
	UWorld* World;

};
