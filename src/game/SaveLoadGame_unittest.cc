#include "gtest/gtest.h"

#include "GameSettings.h"
#include "SaveLoadGame.h"
#include "FileMan.h"
#include "externalized/TestUtils.h"

const uint8_t s_savedGameHeaderVanilla[] = {
	0x63,0x00,0x00,0x00,0x42,0x75,0x69,0x6c,0x64,0x20,0x30,0x34,0x2e,0x31,0x32,0x2e,
	0x30,0x32,0x00,0x00,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x09,0x33,0x0f,0x00,
	0x04,0x00,0x00,0x06,0xe6,0x32,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x01,0x19,0x01,
	0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8c,0x04,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const uint8_t s_savedGameHeaderStracLinux[] = {
	0x63,0x00,0x00,0x00,0x42,0x75,0x69,0x6c,0x64,0x20,0x30,0x34,0x2e,0x31,0x32,0x2e,
	0x30,0x32,0x00,0x00,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x09,0x00,
	0x01,0x00,0x00,0x01,0x10,0xa4,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
	0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x2f,0xe8,0x1a,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

TEST(SaveLoadGameTest, structSizes)
{
	EXPECT_EQ(sizeof(s_savedGameHeaderVanilla),    SAVED_GAME_HEADER_ON_DISK_SIZE);
	EXPECT_EQ(sizeof(s_savedGameHeaderStracLinux), SAVED_GAME_HEADER_ON_DISK_SIZE_STRAC_LIN);
}


TEST(SaveLoadGameTest, structParsers)
{
	// Vanilla header
	{
		SAVED_GAME_HEADER header;
		ParseSavedGameHeader(s_savedGameHeaderVanilla, header, false);
		EXPECT_EQ(header.uiSavedGameVersion,          0x63);
		EXPECT_STREQ(header.zGameVersionNumber,       "Build 04.12.02");
		EXPECT_STREQ(header.sSavedGameDesc,           L"9");
		EXPECT_EQ(header.uiDay,                       2);
		EXPECT_EQ(header.ubHour,                      9);
		EXPECT_EQ(header.ubMin,                       51);
		EXPECT_EQ(header.sSectorX,                    15);
		EXPECT_EQ(header.sSectorY,                    4);
		EXPECT_EQ(header.bSectorZ,                    0);
		EXPECT_EQ(header.ubNumOfMercsOnPlayersTeam,   6);
		EXPECT_EQ(header.iCurrentBalance,             13030);
		// UINT32   uiCurrentScreen;
		// BOOLEAN  fAlternateSector;
		// BOOLEAN  fWorldLoaded;
		// UINT8    ubLoadScreenID;
		EXPECT_EQ(header.sInitialGameOptions.fGunNut,                 1);
		EXPECT_EQ(header.sInitialGameOptions.fSciFi,                  1);
		EXPECT_EQ(header.sInitialGameOptions.ubDifficultyLevel,       DIF_LEVEL_EASY);
		EXPECT_EQ(header.sInitialGameOptions.fTurnTimeLimit,          0);
		EXPECT_EQ(header.sInitialGameOptions.ubGameSaveMode,          0);
		// UINT32 uiRandom;
	}

	// Stracciatella Linux header
	{
		SAVED_GAME_HEADER header;
		ParseSavedGameHeader(s_savedGameHeaderStracLinux, header, true);
		EXPECT_EQ(header.uiSavedGameVersion,          0x63);
		EXPECT_STREQ(header.zGameVersionNumber,       "Build 04.12.02");
		EXPECT_STREQ(header.sSavedGameDesc,           L"1");
		EXPECT_EQ(header.uiDay,                       1);
		EXPECT_EQ(header.ubHour,                      1);
		EXPECT_EQ(header.ubMin,                       0);
		EXPECT_EQ(header.sSectorX,                    9);
		EXPECT_EQ(header.sSectorY,                    1);
		EXPECT_EQ(header.bSectorZ,                    0);
		EXPECT_EQ(header.ubNumOfMercsOnPlayersTeam,   1);
		EXPECT_EQ(header.iCurrentBalance,             42000);
		// UINT32   uiCurrentScreen;
		// BOOLEAN  fAlternateSector;
		// BOOLEAN  fWorldLoaded;
		// UINT8    ubLoadScreenID;
		EXPECT_EQ(header.sInitialGameOptions.fGunNut,                 1);
		EXPECT_EQ(header.sInitialGameOptions.fSciFi,                  1);
		EXPECT_EQ(header.sInitialGameOptions.ubDifficultyLevel,       DIF_LEVEL_EASY);
		EXPECT_EQ(header.sInitialGameOptions.fTurnTimeLimit,          0);
		EXPECT_EQ(header.sInitialGameOptions.ubGameSaveMode,          0);
		// UINT32 uiRandom;
	}
}


TEST(SaveLoadGameTest, savedGameHeaderValidityCheck)
{
	SAVED_GAME_HEADER header;

	// empty header is not valid
	header = SAVED_GAME_HEADER{};
	EXPECT_EQ(isValidSavedGameHeader(header), false);

	// parse vanilla header with vanilla parser; should be valid
	ParseSavedGameHeader(s_savedGameHeaderVanilla, header, false);
	EXPECT_EQ(isValidSavedGameHeader(header), true);

	// parse "strac linux" header with "strac linux" parser; should be valid
	ParseSavedGameHeader(s_savedGameHeaderStracLinux, header, true);
	EXPECT_EQ(isValidSavedGameHeader(header), true);

	// parse vanilla header with "strac linux" parser; should be invalid
	ParseSavedGameHeader(s_savedGameHeaderVanilla, header, true);
	EXPECT_EQ(isValidSavedGameHeader(header), false);

	// parse "strac linux" header with vanilla parser; should be invalid
	ParseSavedGameHeader(s_savedGameHeaderStracLinux, header, false);
	EXPECT_EQ(isValidSavedGameHeader(header), false);
}

TEST(SaveLoadGameTest, parseHeaderLinux)
{
	bool stracLinuxFormat;

	{
		SAVED_GAME_HEADER header;
		AutoSGPFile f(OpenTestResourceForReading("unittests/saves/strac-linux/SaveGame01.sav"));
		ExtractSavedGameHeaderFromFile(f, header, &stracLinuxFormat);
		ASSERT_EQ(stracLinuxFormat, true);
		ASSERT_EQ(isValidSavedGameHeader(header), true);
		EXPECT_EQ(header.uiSavedGameVersion,          0x63);
		EXPECT_STREQ(header.zGameVersionNumber,       "Build 04.12.02");
		EXPECT_STREQ(header.sSavedGameDesc,           L"1");
		EXPECT_EQ(header.uiDay,                       1);
		EXPECT_EQ(header.ubHour,                      1);
		EXPECT_EQ(header.ubMin,                       0);
		EXPECT_EQ(header.sSectorX,                    9);
		EXPECT_EQ(header.sSectorY,                    1);
		EXPECT_EQ(header.bSectorZ,                    0);
		EXPECT_EQ(header.ubNumOfMercsOnPlayersTeam,   1);
		EXPECT_EQ(header.iCurrentBalance,             42000);
		EXPECT_EQ(header.sInitialGameOptions.fGunNut,                 1);
		EXPECT_EQ(header.sInitialGameOptions.fSciFi,                  1);
		EXPECT_EQ(header.sInitialGameOptions.ubDifficultyLevel,       DIF_LEVEL_EASY);
		EXPECT_EQ(header.sInitialGameOptions.fTurnTimeLimit,          0);
		EXPECT_EQ(header.sInitialGameOptions.ubGameSaveMode,          0);
	}
}

TEST(SaveLoadGameTest, parseHeaderWin)
{
	bool stracLinuxFormat;

	{
		SAVED_GAME_HEADER header;
		AutoSGPFile f(OpenTestResourceForReading("unittests/saves/strac-win/SaveGame09.sav"));
		ExtractSavedGameHeaderFromFile(f, header, &stracLinuxFormat);
		ASSERT_EQ(stracLinuxFormat, false);
		ASSERT_EQ(isValidSavedGameHeader(header), true);
		EXPECT_EQ(header.uiSavedGameVersion,          0x63);
		EXPECT_STREQ(header.zGameVersionNumber,       "Build 04.12.02");
		EXPECT_STREQ(header.sSavedGameDesc,           L"9");
		EXPECT_EQ(header.uiDay,                       2);
		EXPECT_EQ(header.ubHour,                      9);
		EXPECT_EQ(header.ubMin,                       51);
		EXPECT_EQ(header.sSectorX,                    15);
		EXPECT_EQ(header.sSectorY,                    4);
		EXPECT_EQ(header.bSectorZ,                    0);
		EXPECT_EQ(header.ubNumOfMercsOnPlayersTeam,   6);
		EXPECT_EQ(header.iCurrentBalance,             13030);
		EXPECT_EQ(header.sInitialGameOptions.fGunNut,                 1);
		EXPECT_EQ(header.sInitialGameOptions.fSciFi,                  1);
		EXPECT_EQ(header.sInitialGameOptions.ubDifficultyLevel,       DIF_LEVEL_EASY);
		EXPECT_EQ(header.sInitialGameOptions.fTurnTimeLimit,          0);
		EXPECT_EQ(header.sInitialGameOptions.ubGameSaveMode,          0);
	}

	{
		SAVED_GAME_HEADER header;
		AutoSGPFile f(OpenTestResourceForReading("unittests/saves/vanilla-russian/SaveGame06.sav"));
		ExtractSavedGameHeaderFromFile(f, header, &stracLinuxFormat);
		ASSERT_EQ(stracLinuxFormat, false);
		ASSERT_EQ(isValidSavedGameHeader(header), true);
		EXPECT_EQ(header.uiSavedGameVersion,          0x5e);
		EXPECT_STREQ(header.zGameVersionNumber,       "Build 99.06.25");
		EXPECT_STREQ(header.sSavedGameDesc,           L"6");
		EXPECT_EQ(header.uiDay,                       1);
		EXPECT_EQ(header.ubHour,                      1);
		EXPECT_EQ(header.ubMin,                       0);
		EXPECT_EQ(header.sSectorX,                    9);
		EXPECT_EQ(header.sSectorY,                    1);
		EXPECT_EQ(header.bSectorZ,                    0);
		EXPECT_EQ(header.ubNumOfMercsOnPlayersTeam,   1);
		EXPECT_EQ(header.iCurrentBalance,             32000);
		EXPECT_EQ(header.sInitialGameOptions.fGunNut,                 0);
		EXPECT_EQ(header.sInitialGameOptions.fSciFi,                  1);
		EXPECT_EQ(header.sInitialGameOptions.ubDifficultyLevel,       DIF_LEVEL_MEDIUM);
		EXPECT_EQ(header.sInitialGameOptions.fTurnTimeLimit,          0);
		EXPECT_EQ(header.sInitialGameOptions.ubGameSaveMode,          0);
	}
}

TEST(SaveLoadGameTest, parseHeaderMac)
{
	bool stracLinuxFormat;

	{
		SAVED_GAME_HEADER header;
		AutoSGPFile f(OpenTestResourceForReading("unittests/saves/strac-macos/SaveGame09.sav"));
		ExtractSavedGameHeaderFromFile(f, header, &stracLinuxFormat);
		ASSERT_EQ(stracLinuxFormat, true);
		ASSERT_EQ(isValidSavedGameHeader(header), true);
		EXPECT_EQ(header.uiSavedGameVersion,          0x63);
		EXPECT_STREQ(header.zGameVersionNumber,       "Build 04.12.02");
		EXPECT_STREQ(header.sSavedGameDesc,           L"very long description long long long long long");
		EXPECT_EQ(header.uiDay,                       1);
		EXPECT_EQ(header.ubHour,                      1);
		EXPECT_EQ(header.ubMin,                       0);
		EXPECT_EQ(header.sSectorX,                    9);
		EXPECT_EQ(header.sSectorY,                    1);
		EXPECT_EQ(header.bSectorZ,                    0);
		EXPECT_EQ(header.ubNumOfMercsOnPlayersTeam,   1);
		EXPECT_EQ(header.iCurrentBalance,             42000);
		EXPECT_EQ(header.sInitialGameOptions.fGunNut,                 0);
		EXPECT_EQ(header.sInitialGameOptions.fSciFi,                  1);
		EXPECT_EQ(header.sInitialGameOptions.ubDifficultyLevel,       DIF_LEVEL_EASY);
		EXPECT_EQ(header.sInitialGameOptions.fTurnTimeLimit,          0);
		EXPECT_EQ(header.sInitialGameOptions.ubGameSaveMode,          0);
	}
}
