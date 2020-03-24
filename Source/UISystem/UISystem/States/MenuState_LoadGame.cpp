// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuState_LoadGame.h"
#include "UISystem/States/MenuStateFactory.h"
#include "WidgetSwitcher.h"
#include "HAL/FileManager.h"
#include "CustomGameInstance.h"


UMenuStateBase* UMenuState_LoadGame::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget)
{
	FString Input = InKeyEvent.GetKey().ToString();

	if (Input == MenuUp || Input == MenuUpAlt) {

		DecrementIndex();
		RedrawGraphics();
	}
	else if (Input == MenuDown || Input == MenuDownAlt) {

		IncrementIndex();
		RedrawGraphics();
	}
	else if (Input == MenuConfirm) {
		
		LoadGame(GI->SavedGamesPaths.FindChecked((ESavedGame)CurrentIndex));
	}
	else if (Input == MenuEscape) {

		return GI->GetMenuStateFactory()->MakeMainMenuState(OwnerUserWidget);
	}
	else {

		if (GEngine != nullptr) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Input);
		}
	}

	return nullptr;
}

void UMenuState_LoadGame::DrawSavedGame(FString PathToFile, FString NameToDraw, int Index) {

	if (FPaths::FileExists(PathToFile)) {
		FDateTime Date = IFileManager::Get().GetTimeStamp(*PathToFile);
		FString DateString = Date.ToString();
		FString SavedGameName = NameToDraw + " - " + DateString;
		Cast<UTextBlock>(AllLines[Index])->SetText(FText::FromString(SavedGameName));
	}
	else {
		Cast<UTextBlock>(AllLines[Index])->SetText(FText::FromString("..."));
	}
}

void UMenuState_LoadGame::LoadGame(FString SavedGameToLoad) {

	if (FPaths::FileExists(SavedGameToLoad)) {
		UGameplayStatics::OpenLevel(GI->GetWorld(), TEXT("GameplayLevel"), true, "?"+ SavedGameToLoad);
	}
}

void UMenuState_LoadGame::Enter()
{
	// draw graphics here
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame0), "Saved Game 0", 0);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame1), "Saved Game 1", 1);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame2), "Saved Game 2", 2);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame3), "Saved Game 3", 3);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame4), "Saved Game 4", 4);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame5), "Saved Game 5", 5);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame6), "Saved Game 6", 6);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame7), "Saved Game 7", 7);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame8), "Saved Game 8", 8);
	DrawSavedGame(GI->SavedGamesPaths.FindChecked(ESavedGame::ESavedGame9), "Saved Game 9", 9);

	if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(MenuParentWidget->GetWidgetFromName("MenuSwitcher"))) {
		Switcher->SetActiveWidget(MenuParentWidget->GetWidgetFromName("LoadGameMenu"));
	}
	RedrawGraphics();
}
