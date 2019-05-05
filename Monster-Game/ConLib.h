#pragma once
#include <Windows.h>
class ConLib
{
public:
	enum eConColor
	{
		ConRed = 1,
		ConGreen = 2,
		ConBlue = 4,
	};
private:
	HANDLE m_Screen;
	HANDLE m_Keyborad;

	/* Color attributes */
	WORD m_TextColor;
	WORD m_BackgroundColor;
public:
	/* Constructor and destructor */
	ConLib();
	~ConLib();

	/* Set attributes */
	void SetBackgroundColor(WORD Color);
	void SetTextColor(WORD Color);
	void SetTitle(const char* Title);
	void SetPosition(COORD Position);

	/* Output methods */
	void Clear(void);
	void OutputString(const char* String);

	/* Input methods */
	void Read(char* Buffer, DWORD BufferSize);
	int  GetKey(void);
};