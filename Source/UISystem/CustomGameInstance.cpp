// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"
#include "Paths.h"
#include "HAL/FileManager.h"
#include "Engine.h"

void UCustomGameInstance::Init() {

	MenuStateFactory = NewObject<UMenuStateFactory>(this, UMenuStateFactory::StaticClass());
	verifyf(MenuStateFactory->IsValidLowLevel(), TEXT("Error: The instance of UMenuStateFactory is not valid!"));
	
	SavedGamesNames = TMap<ESavedGame, FString>();
	SavedGamesPaths = TMap<ESavedGame, FString>();

	SavedGamesPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());
	IniFilePath = SavedGamesPath + TEXT("/Settings.ini");
	NullSavedGame = TEXT("");

	SavedGamesNames.Add(ESavedGame::ESavedGame0, TEXT("SavedGame0"));
	SavedGamesNames.Add(ESavedGame::ESavedGame1, TEXT("SavedGame1"));
	SavedGamesNames.Add(ESavedGame::ESavedGame2, TEXT("SavedGame2"));
	SavedGamesNames.Add(ESavedGame::ESavedGame3, TEXT("SavedGame3"));
	SavedGamesNames.Add(ESavedGame::ESavedGame4, TEXT("SavedGame4"));
	SavedGamesNames.Add(ESavedGame::ESavedGame5, TEXT("SavedGame5"));
	SavedGamesNames.Add(ESavedGame::ESavedGame6, TEXT("SavedGame6"));
	SavedGamesNames.Add(ESavedGame::ESavedGame7, TEXT("SavedGame7"));
	SavedGamesNames.Add(ESavedGame::ESavedGame8, TEXT("SavedGame8"));
	SavedGamesNames.Add(ESavedGame::ESavedGame9, TEXT("SavedGame9"));

	SavedGamesPaths.Add(ESavedGame::ESavedGame0, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame0) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame1, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame1) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame2, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame2) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame3, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame3) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame4, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame4) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame5, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame5) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame6, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame6) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame7, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame7) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame8, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame8) + TEXT(".sav"));
	SavedGamesPaths.Add(ESavedGame::ESavedGame9, SavedGamesPath + TEXT("/") + SavedGamesNames.FindChecked(ESavedGame::ESavedGame9) + TEXT(".sav"));
	
	MenuMemory = NewObject<UMenuMemory>(this, UMenuMemory::StaticClass());
	verifyf(MenuMemory->IsValidLowLevel(), TEXT("Error: The instance of UMenuMemory is not valid!"));
	MenuMemory->InitializeFromIniFile();
}

AGameStateBase * UCustomGameInstance::GetGameStateBase()
{
	return UGameplayStatics::GetGameState(this);
	verifyf(World != nullptr, TEXT("Error: GameStateBase is null. Did you forget to add the GlobalsActor in the scene?"));
}

APlayerController * UCustomGameInstance::GetPlayerController()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	verifyf(PlayerController->IsValidLowLevel(), TEXT("Error: PlayerController is not valid. Did you forget to add the GlobalsActor in the scene?"));
	return PlayerController;
}

UMenuStateFactory* UCustomGameInstance::GetMenuStateFactory() {

	return MenuStateFactory;
}

UMenuMemory* UCustomGameInstance::GetMenuMemory() {

	return MenuMemory;
}

FString UCustomGameInstance::GetLatestSavedGameFilePath() {

	FString LatestSavedGame = TEXT("");
	double LatestSavedGameAge = -1.0;

	for (int i = 0; i < SavedGamesPaths.Num(); i++) {
		if (FPaths::FileExists(SavedGamesPaths.FindChecked((ESavedGame)i))) {
			FString Path = SavedGamesPaths.FindChecked((ESavedGame)i);
			double OtherAge = IFileManager::Get().GetFileAgeSeconds(*Path);
			if (OtherAge < LatestSavedGameAge || LatestSavedGameAge < 0) {
				LatestSavedGame = Path;
				LatestSavedGameAge = OtherAge;
			}
		}
	}
	if (GEngine != nullptr) {
		FString PrintMessage = "Most recent saved game is " + LatestSavedGame;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, PrintMessage);
	}
	return LatestSavedGame;
}

void UCustomGameInstance::SetMenuParent(UMenu_Parent& Menu) {

	MenuParentWidget = &Menu;
}

UMenu_Parent* UCustomGameInstance::GetMenuParent() {
	return MenuParentWidget;
}