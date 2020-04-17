// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UISystem/GlobalEnums.h"

#include "Menu_Parent.generated.h"

/**
 * 
 */

class USizeBox;
class UMenuStateBase;

UCLASS()
class UISYSTEM_API UMenu_Parent : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
		USizeBox* MainMenu;

	UPROPERTY(meta = (BindWidget))
		USizeBox* LoadGameMenu;

	UPROPERTY(meta = (BindWidget))
		USizeBox* SettingsMenu;

	UPROPERTY(meta = (BindWidget))
		USizeBox* KeyBindingsMenu;

	UPROPERTY()
	UMenuStateBase* State;

	bool bFirstStartup = true;

public:

	virtual bool Initialize() override;

	virtual void MainMenuStartupSetup();

	virtual void GameplayStartupSetup();
	
	virtual void OnMenuButtonDown(EMenuButton Button);// override; const FGeometry& InGeometry, const FKeyEvent& InKeyEvent
protected:

	UPROPERTY()
	class UCustomGameInstance* GI;
};
