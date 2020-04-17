// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_NoMenu.h"
#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"
#include "MenuState_PauseMenu.h"
#include "MenuState_CharacterMenu.h"
#include "MenuState_JournalMenu.h"

UMenuStateBase* UMenuState_NoMenu::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget) {

	if (Button == EMenuButton::ECancel) {

		return GI->GetMenuStateFactory()->MakePauseMenuState(OwnerUserWidget);
	}
	else if (Button == EMenuButton::ECharacter) {

		return GI->GetMenuStateFactory()->MakeCharacterMenuState(OwnerUserWidget);
	}
	else if (Button == EMenuButton::EJournal) {

		return GI->GetMenuStateFactory()->MakeJournalMenuState(OwnerUserWidget);
	}

	return nullptr;
}

void UMenuState_NoMenu::Enter(UMenuStateBase* _PreviousState)
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("NoMenu"));
	}
	RedrawGraphics();
}