// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_PauseMenu.h"
#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "UISystem/States/MenuMemory.h"
#include "CustomGameInstance.h"
#include "MenuState_NewGame.h"
#include "MenuState_ContinueGame.h"
#include "MenuState_SaveGame.h"
#include "MenuState_LoadGame.h"
#include "MenuState_Settings.h"
#include "MenuState_Credits.h"
#include "MenuState_QuitToMenu.h"
#include "MenuState_Quit.h"
#include "MenuState_NoMenu.h"

UMenuStateBase* UMenuState_PauseMenu::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget)
{

	if (Button == EMenuButton::EUp) {

		DecrementIndex();
		RedrawGraphics();
	}
	else if (Button == EMenuButton::EDown) {

		IncrementIndex();
		RedrawGraphics();
	}
	else if (Button == EMenuButton::EInteract) {

		switch ((EPauseMenuSelection)CurrentIndex) {
		case EPauseMenuSelection::ENewGame:
			return GI->GetMenuStateFactory()->MakeNewGameState(OwnerUserWidget);

		case EPauseMenuSelection::EContinueGame:
			if (GI->GetLatestSavedGameFilePath() != GI->NullSavedGame) {
				return GI->GetMenuStateFactory()->MakeContinueGameState(OwnerUserWidget);
			}
			else {
				return nullptr;
			}

		case EPauseMenuSelection::ESaveGame:
			return GI->GetMenuStateFactory()->MakeSaveGameState(OwnerUserWidget);

		case EPauseMenuSelection::ELoadGame:
			return GI->GetMenuStateFactory()->MakeLoadGameState(OwnerUserWidget);

		case EPauseMenuSelection::ESettings:
			return GI->GetMenuStateFactory()->MakeSettingsState(OwnerUserWidget);

		case EPauseMenuSelection::ECredits:
			return GI->GetMenuStateFactory()->MakeCreditsState(OwnerUserWidget);

		case EPauseMenuSelection::EQuitToMenu:
			return GI->GetMenuStateFactory()->MakeQuitToMenuState(OwnerUserWidget);

		case EPauseMenuSelection::EQuit:
			return GI->GetMenuStateFactory()->MakeQuitState(OwnerUserWidget);

		}
	}
	else if (Button == EMenuButton::ECancel) {

		return GI->GetMenuStateFactory()->MakeNoMenuState(OwnerUserWidget);
	}

	return nullptr;
}

void UMenuState_PauseMenu::Enter(UMenuStateBase* _PreviousState)
{
	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		CurrentIndex = Memory->LastPauseMenuIndex;
	}
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("PauseMenu"));
	}
	RedrawGraphics();
}

void UMenuState_PauseMenu::Exit()
{
	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		Memory->LastPauseMenuIndex = CurrentIndex;
	}
}