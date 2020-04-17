// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "MenuStateFactory.generated.h"

/**
 * 
 */
class UMenuState_MainMenu;
class UMenuState_NewGame;
class UMenuState_ContinueGame;
class UMenuState_LoadGame;
class UMenuState_Settings;
class UMenuState_KeyBindings;
class UMenuState_Credits;
class UMenuState_Quit;

class UMenuState_NoMenu;
class UMenuState_PauseMenu;
class UMenuState_SaveGame;
class UMenuState_QuitToMenu;

class UMenuState_CharacterMenu;
class UMenuState_JournalMenu;

UCLASS()
class UISYSTEM_API UMenuStateFactory : public UObject
{
	GENERATED_BODY()
public:

	UMenuState_MainMenu* MakeMainMenuState(UUserWidget& MenuParentWidget);
	UMenuState_NewGame* MakeNewGameState(UUserWidget& MenuParentWidget);
	UMenuState_ContinueGame* MakeContinueGameState(UUserWidget& MenuParentWidget);
	UMenuState_LoadGame* MakeLoadGameState(UUserWidget& MenuParentWidget);
	UMenuState_Settings* MakeSettingsState(UUserWidget& MenuParentWidget);
	UMenuState_KeyBindings* MakeKeyBindingsState(UUserWidget& MenuParentWidget);
	UMenuState_Credits* MakeCreditsState(UUserWidget& MenuParentWidget);
	UMenuState_Quit* MakeQuitState(UUserWidget& MenuParentWidget);

	UMenuState_NoMenu* MakeNoMenuState(UUserWidget& MenuParentWidget);
	UMenuState_PauseMenu* MakePauseMenuState(UUserWidget& MenuParentWidget);
	UMenuState_SaveGame* MakeSaveGameState(UUserWidget& MenuParentWidget);
	UMenuState_QuitToMenu* MakeQuitToMenuState(UUserWidget& MenuParentWidget);

	UMenuState_CharacterMenu* MakeCharacterMenuState(UUserWidget& MenuParentWidget);
	UMenuState_JournalMenu* MakeJournalMenuState(UUserWidget& MenuParentWidget);
};
