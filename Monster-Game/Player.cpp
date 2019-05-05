#include "Player.h"

void CPlayer::Move(COORD Direction)
{
	/* Moves Player */
	m_Position.X += Direction.X;
	m_Position.Y += Direction.Y;
}

void CPlayer::RandomLeap(COORD AreaSize)
{
	/* Makes leap to random position */
	srand(time(NULL));

	/* So, if an arena is of size 40, you get a number between 0 and 39
	and then add one to make sure the numbers are between 1 and 40. */
	m_Position.X = (rand() % (AreaSize.X - 1)) + 1;
	m_Position.Y = (rand() % (AreaSize.Y - 1)) + 1;
}

void CPlayer::GetPosition(COORD * Position)
{
	/*Gets player position*/
	memcpy(Position, &m_Position, sizeof(COORD));
}

void CPlayer::SetLives(short Lives)
{
	/* Sets player lives */
	m_Lives = Lives;
}

short CPlayer::GetLives(void)
{
	/* Gets player lives */
	return m_Lives;
}

void CPlayer::SetScore(int Score)
{
	/* Sets player score */
	m_Score = Score;
}

int CPlayer::GetScore(void)
{
	/* Gets player Score */
	return m_Score;
}

void CPlayer::SetLeaps(int Leaps)
{
	/* Sets player available leaps */
	m_Leaps = Leaps;
}

int CPlayer::GetLeaps(void)
{
	/* Gets player availbale leaps */
	return m_Leaps;
}
