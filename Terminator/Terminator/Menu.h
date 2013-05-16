//**************************
// MENU HEADER
//**************************
#ifndef MENU_H
#define MENU_H

#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Menu
{
public:
    int DisplayMenu();
	void ServerBrowser(string PanelHeaders[2]);	
	string SetUsername(string PanelHeaders[3]);		
	void Settings(string PanelHeader[4]);				
	void DisplayAbout(string PanelHeaders[5]);	
};

#endif 