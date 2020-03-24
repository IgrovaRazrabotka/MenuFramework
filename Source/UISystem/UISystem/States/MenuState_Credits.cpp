// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_Credits.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "CustomGameInstance.h"


UMenuStateBase* UMenuState_Credits::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget)
{
	FString Input = InKeyEvent.GetKey().ToString();

	if (Input == MenuEscape) {

		return GI->GetMenuStateFactory()->MakeMainMenuState(OwnerUserWidget);
	}
	else {

		if (GEngine != nullptr) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Input);
		}
	}

	return nullptr;
}

void UMenuState_Credits::Enter()
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("CreditsMenu"));
	}
	RedrawGraphics();

	if (GEngine != nullptr) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Display credits here..."));
	}
}