// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_Quit.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CustomGameInstance.h"


UMenuStateBase* UMenuState_Quit::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget)
{
	if (Button == EMenuButton::EUp) {

		DecrementIndex();
		RedrawGraphics();
	}
	else if (Button == EMenuButton::EDown) {

		IncrementIndex();
		RedrawGraphics();
	}

	return nullptr;
}

void UMenuState_Quit::Enter(UMenuStateBase* _PreviousState)
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("QuitToMenu"));
	}
	RedrawGraphics();

	UKismetSystemLibrary::QuitGame(GI->GetWorld(), GI->GetPlayerController(), EQuitPreference::Quit, true);
}