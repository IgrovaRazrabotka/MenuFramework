// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Widget.h"
#include "MenuStateBase.generated.h"

/**
 * 
 */
UCLASS()
class UISYSTEM_API UMenuStateBase : public UObject
{
	GENERATED_BODY()

	virtual void PostInitProperties() override;
	void BeginPlay();
	
public:

	UPROPERTY()
	UUserWidget* MenuParentWidget;

	virtual UMenuStateBase* HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget);
	virtual void Enter();
	virtual void Exit();

protected:
	virtual void IncrementIndex();
	virtual void DecrementIndex();
	virtual void RedrawGraphics();

	int MinIndex = 0;
	int MaxIndex = 0;
	int ArraySize = 0;
	int CurrentIndex = 0;

	UPROPERTY()
	FSlateFontInfo  UnselectedFont;
	UPROPERTY()
	FSlateFontInfo	SelectedFont;

	UPROPERTY()
	TArray<UWidget*> AllLines;

	UPROPERTY()
	class UCustomGameInstance* GI;

protected:

	FString MenuUp = "W";
	FString MenuDown = "S";
	FString MenuUpAlt = "Up";
	FString MenuDownAlt = "Down";
	FString MenuLeft = "Left";
	FString MenuLeftAlt = "A";
	FString MenuRight = "Right";
	FString MenuRightAlt = "D";
	FString MenuConfirm = "Enter";
	FString MenuEscape = "Escape";

	FString CharacterMenu = "C";
	FString JournalMenu = "J";
};