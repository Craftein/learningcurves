//**************************
// FUNCTION HEADER
//**************************
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Functions
{
public:
	void ServerBrowser(string PanelHeaders[2]);	
	string SetUsername(string PanelHeaders[3]);		
	void Settings(string PanelHeader[4]);				
	void DisplayAbout(string PanelHeaders[5]);	
};

#endif 