// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu_Parent.h"
#include "Engine.h"
#include "UISystem/States/MenuStateFactory.h"
#include "CustomGameInstance.h"

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
		State->Enter();
		bFirstStartup = false;
	}
}

void UMenu_Parent::GameplayStartupSetup()
{
	if (bFirstStartup) {
		State = GI->GetMenuStateFactory()->MakeNoMenuState(*this);
		State->Enter();
		bFirstStartup = false;
	}
}

FReply UMenu_Parent::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	UMenuStateBase* NewState = State->HandleInput(InKeyEvent,*this);
	if (NewState != nullptr) {
		
		State->Exit();

		State = NewState;
		State->Enter();
	}
	return FReply::Handled();
}