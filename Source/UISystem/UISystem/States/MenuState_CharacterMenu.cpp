// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuState_CharacterMenu.h"

#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"


UMenuStateBase* UMenuState_CharacterMenu::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget) {

	FString Input = InKeyEvent.GetKey().ToString();

	if (Input == MenuEscape) {

		return GI->GetMenuStateFactory()->MakeNoMenuState(OwnerUserWidget);
	}
	else if (Input == CharacterMenu) {

		return GI->GetMenuStateFactory()->MakeNoMenuState(OwnerUserWidget);
	}
	else {

		if (GEngine != nullptr) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Input);
		}
	}

	return nullptr;
}

void UMenuState_CharacterMenu::Enter()
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {

		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("CharacterMenu"));
	}
	RedrawGraphics();
}