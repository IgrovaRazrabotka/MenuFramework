// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_MainMenu.h"
#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"


UMenuStateBase* UMenuState_MainMenu::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget)
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
	else if (Input == MenuEscape) {


	}
	else {
		
		if (GEngine != nullptr) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Input);
		}
	}

	return nullptr;
}

void UMenuState_MainMenu::Enter()
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


