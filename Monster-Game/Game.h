#pragma once
#include <Windows.h>
#include <stdio.h>
#include "ConLib.h"
#include "Player.h"
class CGame
{
public:
	/* Game Status enumerator */
	enum eGameStatus
	{
		GameMainMenu = 1,
		GameRunning = 2,
		GamePaused = 3,
		GameWon = 4,
		GameLostLife = 5,
		GameLost = 6,
		GameExit = 7,
		GameSplashScreen = 8,
	};

	/* Game difficulty enumerator */
	enum eGameDifficulty
	{
		GameEasy = 1,
		GameMedium = 2,
		GameHard = 3
	};

private:
	/* Input/Output information */
	ConLib* m_Console;
	int     m_LastAction;

	/* Game Information */
	int     m_GameStatus;
	COORD   m_Arena;
	CPlayer m_Player;
	COORD*  m_Monsters;
	int     m_MonstersNumber;

public:
	/*Constructors and destructor*/
	CGame();
	CGame(ConLib* Console);
	~CGame();

	/* Shows the relative inforamtion depending on game status */
	void ShowSplash(void);
	void ShowMenu(void);
	void ShowGame(void);
	void ShowWon(void);
	void ShowLostLife(void);
	void ShowLost(void);
	void ShowExit(void);
	void Show(void);

	/* Process the turn depending on game status */
	void ProcessSplash(void);
	void ProcessMenu(void);
	void ProcessGame(void);
	void ProcessWon(void);
	void ProcessLostLife(void);
	void ProcessLost(void);
	void ProcessExit(void);
	void ProcessTurn(void);
	void Process(void);

	/* Set console information */
	void SetConsole(ConLib* Console);

	/* Game Methods */
	void StartNewGame(int Difficulty);
	void EndGame(void);
	void CheckCollisions();
	int  GetAction(void);
	int  GetStatus(void);
	void MoveMonsters(void);
};