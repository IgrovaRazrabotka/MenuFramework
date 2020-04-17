// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
enum class EGraphicsLevel {
	ELow = 0,
	EMedium = 1,
	EHigh = 2,
	EEpic = 3
};

enum class EShowSubtitles {
	EShow = 0,
	EDoNotShow = 1
};

enum class ESavedGame {
	ESavedGame0 = 0,
	ESavedGame1 = 1,
	ESavedGame2 = 2,
	ESavedGame3 = 3,
	ESavedGame4 = 4,
	ESavedGame5 = 5,
	ESavedGame6 = 6,
	ESavedGame7 = 7,
	ESavedGame8 = 8,
	ESavedGame9 = 9
};

enum class EMainMenuSelection {
	ENewGame = 0,
	EContinueGame = 1,
	ELoadGame = 2,
	ESettings = 3,
	ECredits = 4,
	EQuit = 5
};

enum class EPauseMenuSelection {
	ENewGame = 0,
	EContinueGame = 1,
	ELoadGame = 2,
	ESaveGame = 3,
	ESettings = 4,
	ECredits = 5,
	EQuitToMenu = 6,
	EQuit = 7
};

enum class ESettingsMenuSelection {
	EGraphicsLevel = 0,
	EShowSubtitles = 1,
	EKeyBindings = 2
};

enum class EMenuButton {
	EUp = 0,
	EDown,
	ELeft,
	ERight,
	EInteract,
	ECancel,
	ECharacter,
	EJournal
};

enum class EMenuState {
	EMainMenu = 0,
	EGameplay
};
