// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayController.h"
#include "UObject/ConstructorHelpers.h"
#include "UserWidget.h"
#include "UISystem/UI/Menu_Parent.h"
#include "CustomGameInstance.h"

AGameplayController::AGameplayController() {

	static ConstructorHelpers::FClassFinder<UUserWidget> MenuWidgetClassFinder(TEXT("/Game/UI/MenuWidget"));
	if (MenuWidgetClassFinder.Succeeded()) {
		MenuWidgetClass = MenuWidgetClassFinder.Class;
	}
}

void AGameplayController::BeginPlay() {

	Super::BeginPlay();

	if (UMenu_Parent* MenuParent = Cast<UMenu_Parent>(CreateWidget(GetGameInstance(), MenuWidgetClass, TEXT("MenuWidget"))))
	{
		if (UCustomGameInstance* GI = GetGameInstance<UCustomGameInstance>()) {
			MenuParent->GameplayStartupSetup();
			MenuParent->AddToViewport();
			GI->SetMenuParent(*MenuParent);
			FInputModeGameOnly InputMode;
			SetInputMode(InputMode);
		}
	}
}