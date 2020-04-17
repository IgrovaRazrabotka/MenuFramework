// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuMemory.h"
#include "FileHelper.h"
#include "Paths.h"
#include "Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"


void UMenuMemory::PostInitProperties() {

	Super::PostInitProperties();

	if (GetOuter() && GetOuter()->GetWorld()) {
		BeginPlay();
	}

}

void UMenuMemory::BeginPlay() {

	GI = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(this));
}


void UMenuMemory::InitializeFromIniFile() {

	FString Path = GI->IniFilePath;

	FString InitialRead = "";
	if (!FFileHelper::LoadFileToString(InitialRead, *Path, FFileHelper::EHashOptions::None)) {// if no file was found
		WriteToIniFile();//make one
	}
	else {
		ParseIniFile(InitialRead);// otherwise parse the existing one
	}
}
void UMenuMemory::WriteToIniFile() {
	
	FString Path = GI->IniFilePath;
	
	FString GraphicsLevelToWrite = "GraphicsLevel=";
	switch (GraphicsLevel)
	{
	case EGraphicsLevel::ELow:
		GraphicsLevelToWrite.Append("Low\n");
		break;
	case EGraphicsLevel::EMedium:
		GraphicsLevelToWrite.Append("Medium\n");
		break;
	case EGraphicsLevel::EHigh:
		GraphicsLevelToWrite.Append("High\n");
		break;
	case EGraphicsLevel::EEpic:
		GraphicsLevelToWrite.Append("Epic\n");
		break;
	default:
		GraphicsLevelToWrite.Append("Low\n");
		break;
	}
	FFileHelper::SaveStringToFile(GraphicsLevelToWrite, *Path, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get());

	FString ShowSubtitlesToWrite = "ShowSubtitles=";
	switch (ShowSubtitles) {
	case EShowSubtitles::EShow:
		ShowSubtitlesToWrite.Append("Yes\n");
		break;
	case EShowSubtitles::EDoNotShow:
		ShowSubtitlesToWrite.Append("No\n");
		break;
	default:
		ShowSubtitlesToWrite.Append("Yes\n");
		break;
	}

	FFileHelper::SaveStringToFile(ShowSubtitlesToWrite, *Path, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}

void UMenuMemory::ParseIniFile(FString FileContents) {

	if (FileContents.IsEmpty()) { // if the contents of the file is empty
		WriteToIniFile();// write the contents
	}
	else {

		TArray<FString> Lines;
		FileContents.ParseIntoArrayLines(Lines, true);
		if (Lines.IsValidIndex(0)) {
			ParseGraphicsSettings(Lines[0]);
		}
		else {
			WriteToIniFile();
			InitializeFromIniFile();
			return;
		}
		if (Lines.IsValidIndex(1)) {
			ParseShowSubtitlesSettings(Lines[1]);
		}
		else {
			WriteToIniFile();
			InitializeFromIniFile();
			return;
		}
	}
}

void UMenuMemory::ParseGraphicsSettings(FString LineContents) {
	
	TArray<FString> GraphicsLineRead;
	LineContents.ParseIntoArray(GraphicsLineRead, TEXT("="), true);
	if (GraphicsLineRead.IsValidIndex(0) && GraphicsLineRead.IsValidIndex(1)) {
		FString GraphicsLineName = GraphicsLineRead[0];
		FString GraphicsLineValue = GraphicsLineRead[1];

		if (GraphicsLineName == "GraphicsLevel") {
			if (GraphicsLineValue == "Low") {
				GraphicsLevel = EGraphicsLevel::ELow;
				return;
			}
			else if (GraphicsLineValue == "Medium") {
				GraphicsLevel = EGraphicsLevel::EMedium;
				return;
			}
			else if (GraphicsLineValue == "High") {
				GraphicsLevel = EGraphicsLevel::EHigh;
				return;
			}
			else if (GraphicsLineValue == "Epic") {
				GraphicsLevel = EGraphicsLevel::EEpic;
				return;
			}
			else {
				WriteToIniFile();//create new contents as old ones are invalid
				InitializeFromIniFile();
				return;
			}
		}
	}
	//if the function does not return it means the file was bad in some way
	WriteToIniFile();
	InitializeFromIniFile();
}

void UMenuMemory::ParseShowSubtitlesSettings(FString LineContents) {

	TArray<FString> ShowSubtitlesLineRead;
	LineContents.ParseIntoArray(ShowSubtitlesLineRead, TEXT("="), true);
	if (ShowSubtitlesLineRead.IsValidIndex(0) && ShowSubtitlesLineRead.IsValidIndex(1)) {
		FString ShowSubtitlesName = ShowSubtitlesLineRead[0];
		FString ShowSubtitlesValue = ShowSubtitlesLineRead[1];

		if (ShowSubtitlesName == "ShowSubtitles") {
			if (ShowSubtitlesValue == "Yes") {
				ShowSubtitles = EShowSubtitles::EShow;
				return;
			}
			else if (ShowSubtitlesValue == "No") {
				ShowSubtitles = EShowSubtitles::EDoNotShow;
				return;
			}
		}
	}
	//if the function does not return it means the file was bad in some way
	WriteToIniFile();
	InitializeFromIniFile();
}

void UMenuMemory::SetCurrentGraphicsLevel(enum EGraphicsLevel _GraphicsLevel) {
	GraphicsLevel = _GraphicsLevel;

	switch (GraphicsLevel) {
	case EGraphicsLevel::ELow:
		SetGraphicsLevelLow();
		break;
	case EGraphicsLevel::EMedium:
		SetGraphicsLevelMedium();
		break;
	case EGraphicsLevel::EHigh:
		SetGraphicsLevelHigh();
		break;
	case EGraphicsLevel::EEpic:
		SetGraphicsLevelEpic();
		break;
	}
	WriteToIniFile();
}

void UMenuMemory::ApplyCurrentGraphicsLevel() {

	SetCurrentGraphicsLevel(GraphicsLevel);
}

void UMenuMemory::SetGraphicsLevelLow()
{
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("r.ScreenPercentage 100"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.ViewDistanceQuality 0"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.AntiAliasingQuality 0"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.PostProcessQuality 0"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.ShadowQuality 0"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.TextureQuality 0"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.EffectsQuality 0"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.FoliageQuality 0"));
}

EGraphicsLevel UMenuMemory::GetCurrentGraphicsLevel() {

	return GraphicsLevel;
}


void UMenuMemory::SetGraphicsLevelMedium()
{
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("r.ScreenPercentage 100"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.ViewDistanceQuality 1"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.AntiAliasingQuality 1"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.PostProcessQuality 1"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.ShadowQuality 1"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.TextureQuality 1"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.EffectsQuality 1"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.FoliageQuality 1"));
}

void UMenuMemory::SetGraphicsLevelHigh()
{
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("r.ScreenPercentage 100"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.ViewDistanceQuality 2"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.AntiAliasingQuality 2"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.PostProcessQuality 2"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.ShadowQuality 2"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.TextureQuality 2"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.EffectsQuality 2"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.FoliageQuality 2"));
}

void UMenuMemory::SetGraphicsLevelEpic()
{
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("r.ScreenPercentage 100"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.ViewDistanceQuality 3"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.AntiAliasingQuality 3"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.PostProcessQuality 3"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.ShadowQuality 3"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.TextureQuality 3"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.EffectsQuality 3"));
	GI->GetWorld()->Exec(GI->GetWorld(), TEXT("sg.FoliageQuality 3"));
}

void UMenuMemory::SetCurrentShowSubtitlesState(enum EShowSubtitles _ShowSubtitles) {
	
	ShowSubtitles = _ShowSubtitles;

	switch (ShowSubtitles) {
	case EShowSubtitles::EShow:
		// put respective gameplay code here as it is pointless to do it in the menu
		break;
	case EShowSubtitles::EDoNotShow:
		//again, same here
		break;
	}
	WriteToIniFile();
}

void UMenuMemory::ApplyCurrentShowSubtitlesState() {

	SetCurrentShowSubtitlesState(ShowSubtitles);
}

EShowSubtitles UMenuMemory::GetCurrentShowSubtitlesState() {

	return ShowSubtitles;
}

void UMenuMemory::SetMenuState(EMenuState NewState) {
	MenuState = NewState;
}

EMenuState UMenuMemory::GetMenuState() {
	return MenuState;
}
