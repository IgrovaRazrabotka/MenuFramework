// Fill out your copyright notice in the Description page of Project Settings.

#include "UISystem/States/MenuStateBase.h"
#include "TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"


void UMenuStateBase::PostInitProperties() {

	Super::PostInitProperties();

	if (GetOuter() && GetOuter()->GetWorld()) BeginPlay();

}

void UMenuStateBase::BeginPlay() {

	GI = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(this));
}

UMenuStateBase* UMenuStateBase::HandleInput(const FKeyEvent& InKeyEvent, UUserWidget& OwnerUserWidget) {

	return nullptr;
}

void UMenuStateBase::Enter() {

}

void UMenuStateBase::Exit() {

}

void UMenuStateBase::IncrementIndex()
{
	if (CurrentIndex >= MaxIndex) {
		CurrentIndex = MinIndex;
	}
	else {
		CurrentIndex++;
	}
}
void UMenuStateBase::DecrementIndex()
{
	if (CurrentIndex <= MinIndex) {
		CurrentIndex = MaxIndex;
	}
	else {
		CurrentIndex--;
	}
}

void UMenuStateBase::RedrawGraphics() {

	for (int i = 0; i < AllLines.Num(); i++) {

		if (i == CurrentIndex) {
			Cast<UTextBlock>(AllLines[i])->SetFont(SelectedFont);
		}
		else {
			Cast<UTextBlock>(AllLines[i])->SetFont(UnselectedFont);
		}
	}
}