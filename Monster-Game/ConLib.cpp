#include "ConLib.h"

ConLib::ConLib()
{
	/* Get standard screen and keyboard handles */
	m_Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	m_Keyborad = GetStdHandle(STD_INPUT_HANDLE);

	SetTextColor(ConRed);
	SetBackgroundColor(0);
}

ConLib::~ConLib()
{
	/* Does nothing */
}

void ConLib::SetBackgroundColor(WORD Color)
{
	m_BackgroundColor = 0;
	/* Use bit manipulation to get the color combinations */
	if (Color& ConGreen) //(Color& ConGreen)
	{
		m_BackgroundColor |= BACKGROUND_GREEN;
	}
	if (Color& ConRed) //(Color& ConRed)
	{
		m_BackgroundColor |= BACKGROUND_RED;
	}
	if (Color& ConBlue) //(Color& ConBlue)
	{
		m_BackgroundColor |= BACKGROUND_BLUE;
	}

	/* Set the color using combinations from above */
	SetConsoleTextAttribute(m_Screen, m_TextColor | m_BackgroundColor);
}

void ConLib::SetTextColor(WORD Color)
{
	m_TextColor = 0;

	/* Use bit manipulation to get the color combinations */
	if (Color & ConRed)
	{
		m_TextColor |= FOREGROUND_RED;
	}
	if (Color & ConGreen)
	{
		m_TextColor |= FOREGROUND_GREEN;
	}
	if (Color & ConBlue)
	{
		m_TextColor |= FOREGROUND_BLUE;
	}

	/* Set the color using combinations from above */
	SetConsoleTextAttribute(m_Screen, m_TextColor | m_BackgroundColor);
}

void ConLib::SetTitle(const char * Title)
{
	/* Sets Window title */
	SetConsoleTitle(Title);
}

void ConLib::SetPosition(COORD Position)
{
	/* Sets The cursor position */
	SetConsoleCursorPosition(m_Screen, Position);
}

void ConLib::Clear(void)
{
	/* Clears the screen */
	COORD Start;
	DWORD Written;

	Start.X = 0;
	Start.Y = 0;

	FillConsoleOutputAttribute(m_Screen, m_TextColor | m_BackgroundColor, 80 * 25, Start, &Written);

	FillConsoleOutputCharacter(m_Screen, ' ', 80 * 25, Start, &Written);

	SetConsoleCursorPosition(m_Screen, Start);
}

void ConLib::OutputString(const char * String)
{
	/* Sends a string to the screen */
	DWORD Written;
	WriteConsole(m_Screen, String, strlen(String), &Written, NULL);
}

void ConLib::Read(char * Buffer, DWORD BufferSize)
{
	/* Reads a string from the keyboard */
	DWORD Read;
	ReadConsole(m_Keyborad, Buffer, BufferSize, &Read, NULL);
}

int ConLib::GetKey(void)
{
	/* Gets a key from the keyboard */
	DWORD Read;
	INPUT_RECORD Event;

	/* Get Console Input */
	ReadConsoleInput(m_Keyborad, &Event, 1, &Read);

	/* If input event is a key evenet see if there is any key pressed and return its virtual- key code*/
	if (Event.EventType == KEY_EVENT)
	{
		if (Event.Event.KeyEvent.bKeyDown)
		{
			return Event.Event.KeyEvent.wVirtualKeyCode;
		}
	}

	return 0;
}
