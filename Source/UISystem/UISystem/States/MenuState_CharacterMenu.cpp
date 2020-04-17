// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuState_CharacterMenu.h"

#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"
#include "MenuState_NoMenu.h"


UMenuStateBase* UMenuState_CharacterMenu::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget) {

	if (Button == EMenuButton::ECancel) {

		return GI->GetMenuStateFactory()->MakeNoMenuState(OwnerUserWidget);
	}
	else if (Button == EMenuButton::ECharacter) {

		return GI->GetMenuStateFactory()->MakeNoMenuState(OwnerUserWidget);
	}

	return nullptr;
}

void UMenuState_CharacterMenu::Enter(UMenuStateBase* _PreviousState)
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {

		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("CharacterMenu"));
	}
	RedrawGraphics();
}