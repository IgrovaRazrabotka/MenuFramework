// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "SizeBox.h"
#include "UISystem/States/MenuStateBase.h"

#include "Menu_Parent.generated.h"

/**
 * 
 */
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

protected:

	UFUNCTION(BlueprintCallable)
	virtual void MainMenuStartupSetup();

	UFUNCTION(BlueprintCallable)
	virtual void GameplayStartupSetup();

	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	
	UPROPERTY()
	class UCustomGameInstance* GI;
};
