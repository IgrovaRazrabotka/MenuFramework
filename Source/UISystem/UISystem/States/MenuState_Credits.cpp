// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_Credits.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"
#include "MenuState_MainMenu.h"
#include "MenuState_PauseMenu.h"


UMenuStateBase* UMenuState_Credits::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget)
{

	if (Button == EMenuButton::ECancel) {

		if (Cast<UMenuState_MainMenu>(PreviousState)) {
			return GI->GetMenuStateFactory()->MakeMainMenuState(OwnerUserWidget);
		}
		else if (Cast<UMenuState_PauseMenu>(PreviousState)) {
			return GI->GetMenuStateFactory()->MakePauseMenuState(OwnerUserWidget);
		}
	}

	return nullptr;
}

void UMenuState_Credits::Enter(UMenuStateBase* _PreviousState)
{
	PreviousState = _PreviousState;
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("CreditsMenu"));
	}
	RedrawGraphics();

	if (GEngine != nullptr) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Display credits here..."));
	}
}