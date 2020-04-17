// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_MainMenu.h"
#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"
#include "MenuState_NewGame.h"
#include "MenuState_ContinueGame.h"
#include "MenuState_LoadGame.h"
#include "MenuState_Settings.h"
#include "MenuState_Credits.h"
#include "MenuState_Quit.h"


UMenuStateBase* UMenuState_MainMenu::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget)
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

		switch ((EMainMenuSelection)CurrentIndex) {
		case EMainMenuSelection::ENewGame:
			return GI->GetMenuStateFactory()->MakeNewGameState(OwnerUserWidget);
		
		case EMainMenuSelection::EContinueGame:
			if (GI->GetLatestSavedGameFilePath() != GI->NullSavedGame) {
				return GI->GetMenuStateFactory()->MakeContinueGameState(OwnerUserWidget);
			}
			else {
				return nullptr;
			}
		
		case EMainMenuSelection::ELoadGame:
			return GI->GetMenuStateFactory()->MakeLoadGameState(OwnerUserWidget);
		
		case EMainMenuSelection::ESettings:
			return GI->GetMenuStateFactory()->MakeSettingsState(OwnerUserWidget);
		
		case EMainMenuSelection::ECredits:
			return GI->GetMenuStateFactory()->MakeCreditsState(OwnerUserWidget);
		
		case EMainMenuSelection::EQuit:
			return GI->GetMenuStateFactory()->MakeQuitState(OwnerUserWidget);

		}
	}

	return nullptr;
}

void UMenuState_MainMenu::Enter(UMenuStateBase* _PreviousState)
{
	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		CurrentIndex = Memory->LastMainMenuIndex;
	}
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("MainMenu"));
	}
	RedrawGraphics();
}

void UMenuState_MainMenu::Exit()
{
	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		Memory->LastMainMenuIndex = CurrentIndex;
	}
}


