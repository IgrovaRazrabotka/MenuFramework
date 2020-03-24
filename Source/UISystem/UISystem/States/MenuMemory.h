// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "UISystem/GlobalEnums.h"

#include "MenuMemory.generated.h"

/**
 * 
 */

UCLASS()
class UISYSTEM_API UMenuMemory : public UObject
{
	GENERATED_BODY()

	virtual void PostInitProperties() override;
	void BeginPlay();
public:

	int LastMainMenuIndex = 0;
	int LastPauseMenuIndex = 0;
	int LastSettingsMenuIndex = 0;
	int LastKeyBindingsMenuIndex = 0;

	void InitializeFromIniFile();
	void WriteToIniFile();
	void ParseIniFile(FString FileContents);
	void ParseGraphicsSettings(FString LineContents);
	void ParseShowSubtitlesSettings(FString LineContents);

	void SetCurrentGraphicsLevel(enum EGraphicsLevel _GraphicsLevel);
	void ApplyCurrentGraphicsLevel();
	EGraphicsLevel GetCurrentGraphicsLevel();
	
	void SetCurrentShowSubtitlesState(enum EShowSubtitles _ShowSubtitles);
	void ApplyCurrentShowSubtitlesState();
	EShowSubtitles GetCurrentShowSubtitlesState();
private:
	//graphics
	EGraphicsLevel GraphicsLevel = EGraphicsLevel::ELow;
	
	void SetGraphicsLevelLow();
	void SetGraphicsLevelMedium();
	void SetGraphicsLevelHigh();
	void SetGraphicsLevelEpic();

	//subtitles
	EShowSubtitles ShowSubtitles = EShowSubtitles::EShow;
	
protected:
	UPROPERTY()
	class UCustomGameInstance* GI;

};
