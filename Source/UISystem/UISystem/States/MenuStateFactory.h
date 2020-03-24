// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UISystem/States/MenuState_MainMenu.h"
#include "UISystem/States/MenuState_NewGame.h"
#include "UISystem/States/MenuState_ContinueGame.h"
#include "UISystem/States/MenuState_LoadGame.h"
#include "UISystem/States/MenuState_Settings.h"
#include "UISystem/States/MenuState_KeyBindings.h"
#include "UISystem/States/MenuState_Credits.h"
#include "UISystem/States/MenuState_Quit.h"

#include "UISystem/States/MenuState_NoMenu.h"
#include "UISystem/States/MenuState_PauseMenu.h"
#include "UISystem/States/MenuState_SaveGame.h"
#include "UISystem/States/MenuState_QuitToMenu.h"

#include "UISystem/States/MenuState_CharacterMenu.h"
#include "UISystem/States/MenuState_JournalMenu.h"

#include "MenuStateFactory.generated.h"

/**
 * 
 */
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
