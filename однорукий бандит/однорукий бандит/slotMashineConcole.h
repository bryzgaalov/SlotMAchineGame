#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include"бандит.h"

class sloMashineConsole
{
	slotMachiime model;
public:
	sloMashineConsole();
	void start();
	void mainMenu( );
	void addMoneyMenu();
	void changeBetMEnu();
	void pause()const { system("pause"); }

};

