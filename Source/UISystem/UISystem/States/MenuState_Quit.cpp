// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_Quit.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CustomGameInstance.h"


UMenuStateBase* UMenuState_Quit::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget)
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

void UMenuState_Quit::Enter()
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("QuitToMenu"));
	}
	RedrawGraphics();

	UKismetSystemLibrary::QuitGame(GI->GetWorld(), GI->GetPlayerController(), EQuitPreference::Quit, true);
}