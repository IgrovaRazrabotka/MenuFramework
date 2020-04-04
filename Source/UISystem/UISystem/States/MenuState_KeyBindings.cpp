// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_KeyBindings.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"


UMenuStateBase* UMenuState_KeyBindings::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget)
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
	else if (Input == MenuEscape) {

		return GI->GetMenuStateFactory()->MakeSettingsState(OwnerUserWidget);
	}
	else {

		if (GEngine != nullptr) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Input);
		}
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