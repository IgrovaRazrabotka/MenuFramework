// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_PauseMenu.h"
#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "UISystem/States/MenuMemory.h"
#include "CustomGameInstance.h"

UMenuStateBase* UMenuState_PauseMenu::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget)
{
	FString Input = InKeyEvent.GetKey().ToString();

	if (Input == MenuUp || Input == MenuUpAlt) {

		DecrementIndex();
		RedrawGraphics();
	}
	else if (Input == MenuDown || Input == MenuDownAlt) {

		IncrementIndex();
		RedrawGraphics();
	}
	else if (Input == MenuConfirm) {

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
	else if (Input == MenuEscape) {

		return GI->GetMenuStateFactory()->MakeNoMenuState(OwnerUserWidget);
	}
	else {

		if (GEngine != nullptr) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Input);
		}
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