// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_Settings.h"

#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "UISystem/States/MenuMemory.h"
#include "CustomGameInstance.h"
#include "Components/TextBlock.h"
#include "MenuState_KeyBindings.h"
#include "MenuState_MainMenu.h"
#include "MenuState_PauseMenu.h"


UMenuStateBase* UMenuState_Settings::HandleInput(EMenuButton Button, UUserWidget& OwnerUserWidget)
{

	if (Button == EMenuButton::EUp) {

		DecrementIndex();
		RedrawGraphics();
	}
	else if (Button == EMenuButton::EDown) {

		IncrementIndex();
		RedrawGraphics();
	}
	else if (Button == EMenuButton::ERight) {
		
		switch ((ESettingsMenuSelection)CurrentIndex) {
		
		case ESettingsMenuSelection::EGraphicsLevel :
			SelectNextGraphicsLevel();
			break;
		case ESettingsMenuSelection::EShowSubtitles:
			SelectNextShowSubtitles();
			break;
		}
		RedrawGraphics();
	}
	else if (Button == EMenuButton::ELeft) {
		switch ((ESettingsMenuSelection)CurrentIndex) {
		
		case ESettingsMenuSelection::EGraphicsLevel:
			SelectPreviousGraphicsLevel();
			break;
		
		case ESettingsMenuSelection::EShowSubtitles:
			SelectNextShowSubtitles();
			break;
		}
		RedrawGraphics();
	}
	else if (Button == EMenuButton::EInteract) {

		switch ((ESettingsMenuSelection)CurrentIndex) {
		
		case ESettingsMenuSelection::EGraphicsLevel:
			ChangeToGraphicsLevel(SelectedGraphicsLevel);
			break;
		case ESettingsMenuSelection::EShowSubtitles:
			ChangeShowSubtitles();
			break;
		case ESettingsMenuSelection::EKeyBindings:
			return GI->GetMenuStateFactory()->MakeKeyBindingsState(OwnerUserWidget);
			break;

		}
	}
	else if (Button == EMenuButton::ECancel) {

		if(GI->GetMenuMemory()->GetMenuState() == EMenuState::EMainMenu)
		{
			return GI->GetMenuStateFactory()->MakeMainMenuState(OwnerUserWidget);
		}
		else if (GI->GetMenuMemory()->GetMenuState() == EMenuState::EGameplay) {
			return GI->GetMenuStateFactory()->MakePauseMenuState(OwnerUserWidget);
		}
	}

	return nullptr;
}

void UMenuState_Settings::Enter(UMenuStateBase* _PreviousState)
{
	PreviousState = _PreviousState;

	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		CurrentIndex = Memory->LastSettingsMenuIndex;
		SelectedGraphicsLevel = Memory->GetCurrentGraphicsLevel();
		SelectedShowSubtitles = Memory->GetCurrentShowSubtitlesState();
	}
	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("SettingsMenu"));
	}
	RedrawGraphics();
}

void UMenuState_Settings::Exit()
{
	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		Memory->LastSettingsMenuIndex = CurrentIndex;
	}
}

void UMenuState_Settings::ChangeToGraphicsLevel(EGraphicsLevel GraphicsLevel) {

	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
		switch (GraphicsLevel) {
		case EGraphicsLevel::ELow:
			//set to respective level
			Memory->SetCurrentGraphicsLevel(EGraphicsLevel::ELow);
			break;
		case EGraphicsLevel::EMedium:
			//set to respective level
			Memory->SetCurrentGraphicsLevel(EGraphicsLevel::EMedium);
			break;
		case EGraphicsLevel::EHigh:
			//set to respective level
			Memory->SetCurrentGraphicsLevel(EGraphicsLevel::EHigh);
			break;
		case EGraphicsLevel::EEpic:
			//set to respective level
			Memory->SetCurrentGraphicsLevel(EGraphicsLevel::EEpic);
			break;
		}
	}
}

void UMenuState_Settings::ChangeShowSubtitles()
{
	if (UMenuMemory* Memory = GI->GetMenuMemory()) {
	
		switch (SelectedShowSubtitles)
		{
		case EShowSubtitles::EShow:
			Memory->SetCurrentShowSubtitlesState(EShowSubtitles::EShow);
			break;
		case EShowSubtitles::EDoNotShow:
			Memory->SetCurrentShowSubtitlesState(EShowSubtitles::EDoNotShow);
			break;
		}
	}
}

void UMenuState_Settings::SelectNextGraphicsLevel() {
	
	if (SelectedGraphicsLevel == EGraphicsLevel::EEpic) SelectedGraphicsLevel = EGraphicsLevel::ELow;
	else SelectedGraphicsLevel = (enum EGraphicsLevel)(((int)SelectedGraphicsLevel) + 1);
}

void UMenuState_Settings::SelectPreviousGraphicsLevel() {
	
	if (SelectedGraphicsLevel == EGraphicsLevel::ELow) SelectedGraphicsLevel = EGraphicsLevel::EEpic;
	else SelectedGraphicsLevel = (enum EGraphicsLevel)(((int)SelectedGraphicsLevel) - 1);
}

void UMenuState_Settings::SelectNextShowSubtitles() {
	
	switch (SelectedShowSubtitles) {
	case EShowSubtitles::EShow:
		SelectedShowSubtitles = EShowSubtitles::EDoNotShow;
		break;
	case EShowSubtitles::EDoNotShow:
		SelectedShowSubtitles = EShowSubtitles::EShow;
		break;
	}
}

void UMenuState_Settings::RedrawGraphics() {

		Super::RedrawGraphics();
	
		UTextBlock* GraphicsText = Cast<UTextBlock>(AllLines[0]);
		switch (SelectedGraphicsLevel)
		{
		case EGraphicsLevel::ELow:
			GraphicsText->SetText(FText::FromString("Graphics Level - Low"));
			break;
		case EGraphicsLevel::EMedium:
			GraphicsText->SetText(FText::FromString("Graphics Level - Medium"));
			break;
		case EGraphicsLevel::EHigh:
			GraphicsText->SetText(FText::FromString("Graphics Level - High"));
			break;
		case EGraphicsLevel::EEpic:
			GraphicsText->SetText(FText::FromString("Graphics Level - Epic"));
			break;
		}

		UTextBlock* SubtitlesText = Cast<UTextBlock>(AllLines[1]);

		switch (SelectedShowSubtitles)
		{
		case EShowSubtitles::EShow:
			SubtitlesText->SetText(FText::FromString("Show Subtitles - Yes"));
			break;
		case EShowSubtitles::EDoNotShow:
			SubtitlesText->SetText(FText::FromString("Show Subtitles - No"));
			break;
		}
}

