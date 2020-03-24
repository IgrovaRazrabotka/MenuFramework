// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuStateFactory.h"
#include "Engine.h"
#include "WidgetTree.h"
#include "UISystem/States/MenuStateBase.h"
#include "Templates/SharedPointer.h"

UMenuState_MainMenu * UMenuStateFactory::MakeMainMenuState(UUserWidget& MenuParentWidget)
{
	UMenuState_MainMenu* State = nullptr;
		State = NewObject<UMenuState_MainMenu>(this, UMenuState_MainMenu::StaticClass());
		
		State->MenuParentWidget = &MenuParentWidget;
		
		State->SelectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Bold.ttf"), 26);
		State->UnselectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Regular.ttf"), 24);
		
		State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("NewGameLine")));
		State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("ContinueGameLine")));
		State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("LoadGameLine")));
		State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SettingsLine")));
		State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("CreditsLine")));
		State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("QuitLine")));

		State->ArraySize = State->AllLines.Num();
		verifyf(State->ArraySize > 0, TEXT("Error: MakeMainMenuState failed as the ArraySize is 0. Check factory constructor!"));
		State->MinIndex = 0;
		State->MaxIndex = State->ArraySize - 1;
	return State;
}

UMenuState_NewGame * UMenuStateFactory::MakeNewGameState(UUserWidget& MenuParentWidget)
{
	UMenuState_NewGame* State = nullptr;
	State = NewObject<UMenuState_NewGame>(this, UMenuState_NewGame::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;
		
	State->ArraySize = State->AllLines.Num();
	//verification is disabled by design here
	//verifyf(State->ArraySize > 0, TEXT("Error: MakeNewGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = 0;

	return State;
}

UMenuState_ContinueGame * UMenuStateFactory::MakeContinueGameState(UUserWidget & MenuParentWidget)
{
	UMenuState_ContinueGame* State = nullptr;
	State = NewObject<UMenuState_ContinueGame>(this, UMenuState_ContinueGame::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->ArraySize = State->AllLines.Num();
	//verification is disabled by design here
	//verifyf(State->ArraySize > 0, TEXT("Error: MakeContinueGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = 0;

	return State;
}

UMenuState_LoadGame * UMenuStateFactory::MakeLoadGameState(UUserWidget & MenuParentWidget)
{
	UMenuState_LoadGame* State = nullptr;
	State = NewObject<UMenuState_LoadGame>(this, UMenuState_LoadGame::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->SelectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Bold.ttf"), 17);
	State->UnselectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Regular.ttf"), 16);

	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame0")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame1")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame2")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame3")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame4")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame5")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame6")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame7")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame8")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SavedGame9")));

	State->ArraySize = State->AllLines.Num();
	verifyf(State->ArraySize > 0, TEXT("Error: MakeLoadGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = State->ArraySize - 1;

	return State;
}

UMenuState_Settings * UMenuStateFactory::MakeSettingsState(UUserWidget & MenuParentWidget)
{
	UMenuState_Settings* State = nullptr;
	State = NewObject<UMenuState_Settings>(this, UMenuState_Settings::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->SelectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Bold.ttf"), 25);
	State->UnselectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Regular.ttf"), 24);

	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("GraphicsLevel")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("ShowSubtitles")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("KeyBindings")));

	State->ArraySize = State->AllLines.Num();
	verifyf(State->ArraySize > 0, TEXT("Error: MakeSettingsState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = State->ArraySize - 1;

	return State;
}

UMenuState_KeyBindings* UMenuStateFactory::MakeKeyBindingsState(UUserWidget& MenuParentWidget) {
	UMenuState_KeyBindings* State = nullptr;
	State = NewObject<UMenuState_KeyBindings>(this, UMenuState_KeyBindings::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->SelectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Bold.ttf"), 15);
	State->UnselectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Regular.ttf"), 14);

	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command1")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command2")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command3")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command4")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command5")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command6")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command7")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command8")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command9")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("Command10")));

	State->ArraySize = State->AllLines.Num();
	verifyf(State->ArraySize > 0, TEXT("Error: MakeKeyBindingsState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = State->ArraySize - 1;

	return State;
}

UMenuState_Credits * UMenuStateFactory::MakeCreditsState(UUserWidget & MenuParentWidget)
{
	UMenuState_Credits* State = nullptr;
	State = NewObject<UMenuState_Credits>(this, UMenuState_Credits::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->ArraySize = State->AllLines.Num();
	//verification is disabled by design here
	//verifyf(State->ArraySize > 0, TEXT("Error: MakeContinueGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = 0;

	return State;
}

UMenuState_Quit * UMenuStateFactory::MakeQuitState(UUserWidget & MenuParentWidget)
{
	UMenuState_Quit* State = nullptr;
	State = NewObject<UMenuState_Quit>(this, UMenuState_Quit::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->ArraySize = State->AllLines.Num();
	//verification is disabled by design here
	//verifyf(State->ArraySize > 0, TEXT("Error: MakeContinueGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = 0;

	return State;
}

UMenuState_NoMenu* UMenuStateFactory::MakeNoMenuState(UUserWidget& MenuParentWidget) {

	UMenuState_NoMenu* State = nullptr;
	State = NewObject<UMenuState_NoMenu>(this, UMenuState_NoMenu::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->ArraySize = State->AllLines.Num();
	//verification is disabled by design here
	//verifyf(State->ArraySize > 0, TEXT("Error: MakeContinueGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = 0;

	return State;
}

UMenuState_PauseMenu* UMenuStateFactory::MakePauseMenuState(UUserWidget& MenuParentWidget) {

	UMenuState_PauseMenu* State = nullptr;
	State = NewObject<UMenuState_PauseMenu>(this, UMenuState_PauseMenu::StaticClass());

	State->MenuParentWidget = &MenuParentWidget;

	State->SelectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Bold.ttf"), 24);
	State->UnselectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Regular.ttf"), 22);

	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("PauseNewGameLine")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("PauseContinueGameLine")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("PauseLoadGameLine")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("PauseSaveGameLine")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("PauseSettingsLine")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("PauseCreditsLine")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("PauseQuitToMenuLine")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("PauseQuitLine")));

	State->ArraySize = State->AllLines.Num();
	verifyf(State->ArraySize > 0, TEXT("Error: MakePauseMenuState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = State->ArraySize - 1;
	return State;

}

UMenuState_SaveGame* UMenuStateFactory::MakeSaveGameState(UUserWidget& MenuParentWidget) {

	UMenuState_SaveGame* State = nullptr;
	State = NewObject<UMenuState_SaveGame>(this, UMenuState_SaveGame::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->SelectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Bold.ttf"), 17);
	State->UnselectedFont = FSlateFontInfo(TEXT("Slate/Fonts/Roboto-Regular.ttf"), 16);

	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo0")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo1")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo2")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo3")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo4")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo5")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo6")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo7")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo8")));
	State->AllLines.Add(MenuParentWidget.GetWidgetFromName(TEXT("SlotToSaveTo9")));

	State->ArraySize = State->AllLines.Num();
	verifyf(State->ArraySize > 0, TEXT("Error: MakeSaveGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = State->ArraySize - 1;

	return State;
}
UMenuState_QuitToMenu* UMenuStateFactory::MakeQuitToMenuState(UUserWidget& MenuParentWidget) {

	UMenuState_QuitToMenu* State = nullptr;
	State = NewObject<UMenuState_QuitToMenu>(this, UMenuState_QuitToMenu::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->ArraySize = State->AllLines.Num();
	//verification is disabled by design here
	//verifyf(State->ArraySize > 0, TEXT("Error: MakeContinueGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = 0;

	return State;
}

UMenuState_CharacterMenu* UMenuStateFactory::MakeCharacterMenuState(UUserWidget& MenuParentWidget) {

	UMenuState_CharacterMenu* State = nullptr;
	State = NewObject<UMenuState_CharacterMenu>(this, UMenuState_CharacterMenu::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->ArraySize = State->AllLines.Num();
	//verification is disabled by design here
	//verifyf(State->ArraySize > 0, TEXT("Error: MakeContinueGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = 0;

	return State;
}

UMenuState_JournalMenu* UMenuStateFactory::MakeJournalMenuState(UUserWidget& MenuParentWidget) {

	UMenuState_JournalMenu* State = nullptr;
	State = NewObject<UMenuState_JournalMenu>(this, UMenuState_JournalMenu::StaticClass());
	State->MenuParentWidget = &MenuParentWidget;

	State->ArraySize = State->AllLines.Num();
	//verification is disabled by design here
	//verifyf(State->ArraySize > 0, TEXT("Error: MakeContinueGameState failed as the ArraySize is 0. Check factory constructor!"));
	State->MinIndex = 0;
	State->MaxIndex = 0;

	return State;
}
