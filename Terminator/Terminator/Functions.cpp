/****************************************
		Menu Functions
*****************************************/
#include "Display.h"
#include "Menu.h"
#include "Configuration.h"
#include "Functions.h"

string Functions::SetUsername(string PanelHeaders[3])
{	
	Display display;
	Configuration config;

	display.RemoveText();					
	config.SetColour(MenuTitleColour), config.SetXYCoord(42, 10), cout << PanelHeaders[3];
	config.SetColour(StandardColour); 

	string Username;
	string DefaultName = "Default Name";
	if (Username == "")
	{
		Username = DefaultName;
	}
	config.SetXYCoord(30,12), cout << "Set Username: ", getline (cin,Username);
	if (Username == "" || Username.length() > 10 || Username.length() < 3)
	{
		config.SetColour(ErrorColour);
		config.SetXYCoord(47,14), cout << "Error !";
		config.SetXYCoord(30,15), cout << "Username must be between 2 and 10 characters!";
		while (Username == "" || Username.length() > 10 || Username.length() < 2)
		{
			config.SetColour(StandardColour);
			config.SetXYCoord(30,17), cout << "Set Username: ", getline (cin,Username);
		}
	}
	config.SetXYCoord(30,19), cout << "New Username:" << Username;
	return Username;
}

void Functions::Settings(string PanelHeaders[4])
{
	Display display;
	Configuration config;

	display.RemoveText();					
	config.SetColour(MenuTitleColour), config.SetXYCoord(42, 10), std::cout << PanelHeaders[4];
	config.SetColour(StandardColour); 

	config.SetXYCoord(30,12);  cout << ("- IP Address: 192.168.0.1");
	config.SetXYCoord(30,14);  cout << ("- Port Number [TCP]: 5556");
	config.SetXYCoord(30,16);  cout << ("- Port Status: Closed");
	config.SetXYCoord(30,18);  cout << ("------------------------------------------");
	config.SetXYCoord(30,20);  cout << ("- Application Version: 1.0");

}

void Functions::ServerBrowser(string PanelHeaders[2])
{
	Display display;
	Configuration config;

	display.RemoveText();
	config.SetColour(MenuTitleColour), config.SetXYCoord(42, 10), cout << PanelHeaders[2];
	config.SetColour(StandardColour), config.SetXYCoord(30,12);					
	int i = (rand()%8)+1;
	int ListX = 14;
	int x;
	printf("Total Servers: %i", i);
	for(x = 0; x < i; x++)
	{
		config.SetXYCoord(30,ListX++); 
		printf(">> User %x's Chat Room", x+1);
	}
}

void Functions::DisplayAbout(string PanelHeaders[5])
{
	Display display;
	Configuration config;

	display.RemoveText();
	config.SetColour(MenuTitleColour);
	config.SetXYCoord(42, 10), cout << PanelHeaders[5];
	config.SetColour(StandardColour); 

	config.SetXYCoord(30,12);  cout << ("Terminator (Temp Title) Chat Created by...");
	config.SetXYCoord(30,14);  cout << ("- Craftein: Network Programmer");
	config.SetXYCoord(30,16);  cout << ("- NightSlasher: Front End Programmer");
	config.SetXYCoord(30,18);  cout << ("------------------------------------------");
	config.SetXYCoord(30,20);  cout << ("https://github.com/Craftein/learningcurves");
}
