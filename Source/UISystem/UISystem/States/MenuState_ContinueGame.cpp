// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuState_ContinueGame.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"


void UMenuState_ContinueGame::Enter(UMenuStateBase* _PreviousState)
{
	// draw graphics here

		if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
			Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("ContinueGameMenu"));
			FString Path = GI->GetLatestSavedGameFilePath();
			UGameplayStatics::OpenLevel(GI->GetWorld(), TEXT("GameplayLevel"), true, "?ContinueGame");
		}
		RedrawGraphics();

		if (GEngine != nullptr) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Continuing from the most recent saved game here... \
				 Display Loading widget..."));
		}
}