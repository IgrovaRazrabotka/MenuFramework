// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_QuitToMenu.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CustomGameInstance.h"
#include "Kismet/GameplayStatics.h"


UMenuStateBase* UMenuState_QuitToMenu::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget)
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

void UMenuState_QuitToMenu::Enter(UMenuStateBase* _PreviousState)
{
	// draw graphics here
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("QuitMenu"));
	}
	RedrawGraphics();

	UGameplayStatics::OpenLevel(GI->GetWorld(), TEXT("MainMenuLevel"), true);
}