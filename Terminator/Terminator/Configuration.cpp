/****************************************
    Configuration related functions.
*****************************************/
#include "Configuration.h"
#include "Menu.h"
#include "Display.h"
#include "Functions.h"

HANDLE MainConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Configuration::SetXYCoord(int x,int y)
{
	COORD Coord;
	Coord.X=x;
	Coord.Y=y;
	SetConsoleCursorPosition(MainConsole,Coord);
}

void Configuration::SetColour(int colour)
{
	SetConsoleTextAttribute(MainConsole, colour);
}

void Configuration::ConsoleSettings()
{
	SetConsoleTitle(L"Terminator Chat");

	// Hide The Cursor
	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;
	hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	GetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );

	// Remove Scrollbar
	CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
	COORD NewSBSize;
	 
	GetConsoleScreenBufferInfo(MainConsole, &BufferInfo);
	NewSBSize.X = BufferInfo.dwSize.X;
	NewSBSize.Y = BufferInfo.dwSize.Y - 275;
	SetConsoleScreenBufferSize(MainConsole, NewSBSize);
}