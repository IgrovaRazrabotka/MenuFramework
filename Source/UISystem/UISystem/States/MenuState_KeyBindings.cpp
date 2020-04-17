// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_KeyBindings.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"
#include "MenuState_Settings.h"


UMenuStateBase* UMenuState_KeyBindings::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget)
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

		switch (CurrentIndex) {
		case 0:
			//eventually bind key here if you do not want static controls...
			break;
		case 1:
			//and here...
			break;
		case 2:
			//and here...
			break;
			// and here on...
		default:
			break;
		}
	}
	else if (Button == EMenuButton::ECancel) {

		return GI->GetMenuStateFactory()->MakeSettingsState(OwnerUserWidget);
	}

	return nullptr;
}

void UMenuState_KeyBindings::Enter(UMenuStateBase* _PreviousState)
{
	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		CurrentIndex = Memory->LastKeyBindingsMenuIndex;
	}
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("KeyBindingsMenu"));
	}
	RedrawGraphics();
}

void UMenuState_KeyBindings::Exit()
{
	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		Memory->LastKeyBindingsMenuIndex = CurrentIndex;
	}
}