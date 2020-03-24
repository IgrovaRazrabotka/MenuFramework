// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UISystem/States/MenuStateBase.h"
#include "UISystem/GlobalEnums.h"

#include "MenuState_Settings.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API UMenuState_Settings : public UMenuStateBase
{
	GENERATED_BODY()

	friend class UMenuStateFactory;
public:

	virtual UMenuStateBase* HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget) override;
	virtual void Enter() override;
	virtual void Exit() override;

	virtual void RedrawGraphics() override;

protected:
	void ChangeToGraphicsLevel(EGraphicsLevel GraphicsLevel);
	enum EGraphicsLevel SelectedGraphicsLevel = EGraphicsLevel::EEpic;
	void SelectNextGraphicsLevel();
	void SelectPreviousGraphicsLevel();
	
	void ChangeShowSubtitles();
	enum EShowSubtitles SelectedShowSubtitles = EShowSubtitles::EShow;
	void SelectNextShowSubtitles();


	
};
