/****************************************
		Display related functions.
*****************************************/
#include "Display.h"
#include "Menu.h"
#include "Configuration.h"
#include "Functions.h"

void Display::RemoveText()
{
	Configuration config;

	int x;
	config.SetColour(BackGroundColour);
	for(x = 9; x <= 22; x++)
	{
		config.SetXYCoord(27, x);
		cout << "                                                  ";
	}
}

void Display::DrawTitle()
{
	Configuration config;

	int i = 0;
	const int MaxTitleLines = 7;
	config.SetColour(TitleColour);

	char *Title[MaxTitleLines] = 
	{"  _____ _____ ____  __  __ ___ _   _    _  _____ ___  ____  ",
	 " |_   _| ____|  _ \\|  \\/  |_ _| \\ | |  / \\|_   _/ _ \\|  _ \\ ",
	 "   | | |  _| | |_) | |\\/| || ||  \\| | / _ \\ | || | | | |_) |",
	 "   | | | |___|  _ <| |  | || || |\\  |/ ___ \\| || |_| |  _ < ",
	 "   |_| |_____|_| \\_\\_|  |_|___|_| \\_/_/   \\_\\_| \\___/|_| \\_\\",
	 "                                                                   ",
	 "----------------------------- CHAT ----------------------------"};

	for (i=0; i < MaxTitleLines; i++)
	{
		config.SetXYCoord(7, i+1);		
		std::cout << Title[i];
	}
}

void Display::DrawWindows()
{
	Configuration config;

	char *MenuBox = "                    ";
	char *MainPanel = "                                                  ";
	char *SideShadow = " ";

	int i = 0;
	int BgYCoord[MaxBgLines] = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};

	for (i=0; i< MaxBgLines; i++)
	{		
		config.SetColour(BackGroundColour);
		config.SetXYCoord(2, BgYCoord[i]), cout << MenuBox;

		config.SetColour(ShadowColour);
		config.SetXYCoord(22, BgYCoord[i+1]), cout << SideShadow;

		// Display Panel
		
		config.SetColour(BackGroundColour);
		config.SetXYCoord(27, BgYCoord[i]), cout << MainPanel;

		config.SetColour(ShadowColour);		
		config.SetXYCoord(101, BgYCoord[i+1]), cout << SideShadow;
	}
	
	config.SetColour(ShadowColour);
	config.SetXYCoord(3, 23), cout << MenuBox;
	
	config.SetColour(ShadowColour);
	config.SetXYCoord(28, 23), cout << MainPanel;

	config.SetColour(StandardColour); 
	config.SetXYCoord(37, BgYCoord[4]), cout << "Welcome to Terminator chat!";

	config.SetColour(MenuTitleColour);
	config.SetXYCoord(42, BgYCoord[6]), cout << "      NEWS      ";

	config.SetColour(StandardColour);
	config.SetXYCoord(37, BgYCoord[8]), cout << "- News Item #1" ;
	config.SetXYCoord(37, BgYCoord[9]), cout << "- News Item #2" ;
	config.SetXYCoord(37, BgYCoord[10]), cout << "- News Item #3" ;
}