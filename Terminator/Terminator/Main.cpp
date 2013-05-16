/****************************************
		Terminator Chat Main
*****************************************/
// Standard Library Initialisation
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

// Header Initialisation
#include "Menu.h"
#include "Configuration.h"
#include "Display.h"
#include "Functions.h"

using namespace std;

int main()
{	
	Menu menu;
	Configuration config;
	Display display;

	config.ConsoleSettings();
	display.DrawTitle();
	display.DrawWindows();
	menu.DisplayMenu();
}