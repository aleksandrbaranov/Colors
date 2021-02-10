#pragma once
#include<Windows.h>
#include<cstdlib>
/*
	Colors - library for changing the color in the console (Powered by Win32API)
	Class Colors:
	Methods:
		clear - the usual white color of words in the console
		clerar_all - clear the entire console
		set_color  - sets the color that you will pass to it
		the colors start with CL_ ...
		set_intensity - enables the color intensity if set to true and disables it if set to false
*/
#ifdef WIN32
#define CL_RED		0x0001
#define CL_GREEN	0x0002
#define CL_BLUE		0x0003
#define CL_GRAY		0x0004
#define CL_WHITE	0x0005
#define CL_CYAN		0x0006
#define CL_PURPLE	0x0007
#define CL_YELLOW	0x0008

class Colors {

private:
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	bool intensity = false;

public:

	void set_intensity(bool intensity_value) {
		intensity = intensity_value;
	}

	void clear() {
		SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	void clear_all() {
		system("color 7");
	}

	void set_color(int color) {
		if (!intensity) {
			switch (color)
			{ 
			case CL_RED:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED);						break;
			case CL_GREEN:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_GREEN);						break;
			case CL_BLUE:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_BLUE);						break;
			case CL_GRAY:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_INTENSITY);						break;
			case CL_CYAN:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);	break;
			case CL_PURPLE: SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);	break;
			case CL_YELLOW: SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_GREEN);				break;
			case CL_WHITE: clear();													break;
			default:clear();													break;
			};
		}else {
			switch (color)
			{
			case CL_RED:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_INTENSITY);				 break;
			case CL_GREEN:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_GREEN | FOREGROUND_INTENSITY);			 break;
			case CL_BLUE:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_BLUE | FOREGROUND_INTENSITY);			 break;
			case CL_GRAY:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_INTENSITY);						 break;
			case CL_CYAN:	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);	 break;
			case CL_PURPLE: SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);	 break;
			case CL_YELLOW: SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);       break;
			case CL_WHITE: clear();													 break;
			default:clear();													 break;
			};
		}
	}

	~Colors()
	{
		CloseHandle(hConsoleOutput);
	}

};
#else
#error "This library for Windows OS"
#endif 
