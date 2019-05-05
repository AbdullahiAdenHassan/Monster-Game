#include "Game.h"
int main()
{
	ConLib Console;
	CGame Game(&Console);

	/* Set Window Title */
	Console.SetTitle("Monster");

	/* Start and run game */
	while (Game.GetStatus() != Game.GameExit)
	{
		Game.Process();
	}

	system("pause");
	return 0;
}