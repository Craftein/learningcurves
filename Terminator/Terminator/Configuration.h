//**************************
// CONFIG HEADER
//**************************
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

const int MaxNo_Menu = 5;
const int MaxBgLines = 14;
const int MAX_LINE_LENGTH = 79;

class Configuration
{
public:
	void SetXYCoord(int x,int y);
	void SetColour(int colour);
	void ConsoleSettings();
};

#endif 