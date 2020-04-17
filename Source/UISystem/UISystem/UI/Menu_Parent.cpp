// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu_Parent.h"
#include "Engine.h"
#include "UISystem/States/MenuStateFactory.h"
#include "CustomGameInstance.h"
#include "SizeBox.h"
#include "UISystem/States/MenuStateBase.h"
#include "UISystem/States/MenuState_MainMenu.h"
#include "UISystem/States/MenuState_NoMenu.h"

bool UMenu_Parent::Initialize()
{
	Super::Initialize();

	bIsFocusable = true;

	GI = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(this));

	return true;
}

void UMenu_Parent::MainMenuStartupSetup()
{
	if (bFirstStartup) {
		State = GI->GetMenuStateFactory()->MakeMainMenuState(*this);
		State->Enter(nullptr);
		bFirstStartup = false;
		GI->GetMenuMemory()->SetMenuState(EMenuState::EMainMenu);
	}
}

void UMenu_Parent::GameplayStartupSetup()
{
	if (bFirstStartup) {
		State = GI->GetMenuStateFactory()->MakeNoMenuState(*this);
		State->Enter(nullptr);
		bFirstStartup = false;
		GI->GetMenuMemory()->SetMenuState(EMenuState::EGameplay);
	}
}

void UMenu_Parent::OnMenuButtonDown(EMenuButton Button) //const FGeometry& InGeometry, const FKeyEvent& InKeyEvent
{
	UMenuStateBase* NewState = State->HandleInput(Button,*this);
	UMenuStateBase* PreviousState = nullptr;
	if (NewState != nullptr) {
		
		State->Exit();

		PreviousState = State;
		State = NewState;
		State->Enter(PreviousState);
	}
	//return FReply::Handled();
}
