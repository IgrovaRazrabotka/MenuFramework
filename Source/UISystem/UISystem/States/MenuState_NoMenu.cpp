// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_NoMenu.h"
#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"


UMenuStateBase* UMenuState_NoMenu::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget) {

	FString Input = InKeyEvent.GetKey().ToString();

	if (Input == MenuEscape) {

		return GI->GetMenuStateFactory()->MakePauseMenuState(OwnerUserWidget);
	}
	else if (Input == CharacterMenu) {

		return GI->GetMenuStateFactory()->MakeCharacterMenuState(OwnerUserWidget);
	}
	else if (Input == JournalMenu) {

		return GI->GetMenuStateFactory()->MakeJournalMenuState(OwnerUserWidget);
	}
	else {

		if (GEngine != nullptr) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Input);
		}
	}

	return nullptr;
}

void UMenuState_NoMenu::Enter()
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("NoMenu"));
	}
	RedrawGraphics();
}