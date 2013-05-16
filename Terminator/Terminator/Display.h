//**************************
// DISPLAY HEADER
//**************************
#ifndef DISPLAY_H
#define DISPLAY_H

#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

//****************************************************************************************************************************************************************
// Colour ID [Convert from standard hexadecimal to decimal]
const int StandardColour = 112;
const int HoverColour = 10;
const int BackGroundColour = 119;
const int MenuTitleColour = 10;
const int ShadowColour = 136;
const int FontColour = 7;
const int LineBreakColour = 112;
const int TitleColour = 10;
const int ErrorColour = 124;
/***************************************************************************************************************************************************************/

class Display
{
public:
	void RemoveText();
	void DrawTitle();
	void DrawWindows();
};

#endif 