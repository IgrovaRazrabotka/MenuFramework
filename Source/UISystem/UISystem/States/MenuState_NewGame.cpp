// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_NewGame.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"


void UMenuState_NewGame::Enter(UMenuStateBase* _PreviousState)
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("NewGameMenu"));
		UGameplayStatics::OpenLevel(GI->GetWorld(), TEXT("GameplayLevel"));
	}
	RedrawGraphics();

	if (GEngine != nullptr) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Load game world here... Display Loading widget..."));
	}
}