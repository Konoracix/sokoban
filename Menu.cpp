#include <iostream>
#include <cstdlib>
#include "Menu.h"

using namespace std;

void Menu::executeMenu(){
	userInputColorMode();
	userInputRandomLevels();
	Menu::levelNumber = 1;
}

void Menu::clearConsole(){
	#if defined(_WIN32)
		system("cls");
	#elif (defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__))			
		system("clear");
	#endif
}

void Menu::userInputColorMode(){
	clearConsole();
	string status = "";
	cout << "|------------------------------------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|    Do you want to enable color mode?     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|------------------------------------------|" << endl;
	cout << "(Y/n)";
	getline(cin, status);
	setColorModeStatus(status == "Y" or status == "y" or status == "");
	clearConsole();
}

void Menu::userInputRandomLevels(){
	clearConsole();
	string status = "";
	cout << "|------------------------------------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "| Do you want to enable random maps order? |" << endl;
	cout << "|                                          |" << endl;
	cout << "|------------------------------------------|" << endl;
	cout << "(y/N)";
	getline(cin, status);
	setRandomLevelStatus(!(status == "N" or status == "n" or status == ""));
	clearConsole();
}

void Menu::setColorModeStatus(bool state){
	Menu::colorModeStatus = state;
}

void Menu::setRandomLevelStatus(bool state){
	Menu::randomLevelStatus = state;
}

bool Menu::getColorModeStatus(){
	return Menu::colorModeStatus;
}

bool Menu::getRandomLevelStatus(){
	return Menu::randomLevelStatus;
}