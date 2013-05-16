/****************************************
		Menu related functions.
*****************************************/
#include "Menu.h"
#include "Display.h"
#include "Configuration.h"
#include "Functions.h"


int Menu::DisplayMenu()
{
	Display display;
	Configuration config;
	Functions func;

	string PanelHeaders[8] = {"      MENU      ", "     DISPLAY    ", "  SERVER LIST   ", "  SET USERNAME  ", "    SETTINGS    ", "      ABOUT     ", "      QUIT      ", "      NEWS      "};
	string MenuList[MaxNo_Menu] = {"  Server List ", " Set Username ",  "   Settings   ", "     About    ", "     Quit     "};
	int ypos[MaxNo_Menu] = { 12, 14, 16, 18, 20};
    int xpos = 5;

	config.SetColour(MenuTitleColour);
	config.SetXYCoord(4, 10); cout << PanelHeaders[0];
	
	config.SetColour(MenuTitleColour);
	config.SetXYCoord(42, 10); cout << PanelHeaders[1];

	// Show Menu

	int i;
	config.SetColour(StandardColour); 
	for (i=0; i< MaxNo_Menu; ++i)
	{
		config.SetXYCoord(xpos, ypos[i] );
		config.SetColour(StandardColour); 
		cout << MenuList[i];
	}
	// Enable Menu
	i = 0;
	while(1)
	{
		config.SetXYCoord(xpos, ypos[i]);
		config.SetColour(HoverColour);

		cout << MenuList[i];
		switch( _getch() )
		{
			case 72: if(i>0) 
				{
       				config.SetXYCoord(xpos,ypos[i] );
					config.SetColour(StandardColour); // Standard Going Down
					cout << MenuList[i];
					i--;
				}
				break;
			case 80: if(i< MaxNo_Menu-1 )
				{
       				config.SetXYCoord(xpos,ypos[i] );
					config.SetColour(StandardColour); // Standard Going Up
					cout << MenuList[i];
					i++;
				}
				break;
			case 13: 
				if(i==0) 
				{  
					func.ServerBrowser(PanelHeaders);
				}
				if(i==1) 
				{  					
					func.SetUsername(PanelHeaders);
				}
				if(i==2) 
				{					
					func.Settings(PanelHeaders);					
				}
				if(i==3) 
				{		
					func.DisplayAbout(PanelHeaders);
				}
				if(i==4) 
				{  // Exit					
					display.RemoveText();
					config.SetColour(MenuTitleColour), config.SetXYCoord(42, 10), cout << PanelHeaders[6];
					config.SetColour(StandardColour);   

					char Input;					
					config.SetXYCoord(34,12); cout << "Are you sure you want to exit? [Y/N]: ";
					cin >> Input; 

					if (toupper(Input) == 'N')
					{
						break;
					}
					else if (toupper(Input) == 'Y')
					{
						config.SetXYCoord(34,15); return 0;						
					}
					else if (Input == ' ' || Input != toupper('Y') || Input != toupper('N'))
					{
						while(Input == ' ' || Input != toupper('Y') || Input != toupper('N'))
						{	
							config.SetColour(ErrorColour);
							config.SetXYCoord(34,13),cout << "Error: Please Enter [Y/N]: ";
							config.SetColour(StandardColour), cin >> Input;
							if (toupper(Input) == 'N')
							{
								break;
							}
							else if (toupper(Input) == 'Y')
							{									
								config.SetXYCoord(34,15); 
								return 0;							
							}
						}
					}
					
				}
				break;
		}
	}
	return 0;
}

// Error	2	error LNK2019: unresolved external symbol was possibly caused by the lack of Menu::FunctionName 