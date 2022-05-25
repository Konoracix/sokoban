#include <iostream>
#include "MapController.h"
#include "Menu.h"
#include "Dictionary.h"
#include "MoveValidator.h"

#if defined(_WIN32)
	#include <conio.h>
#endif

using namespace std;

int main(){
	Menu menu;
	menu.executeMenu();
	Dictionary dict(menu.getColorModeStatus());
	MapController map(10, 10, 2);
	char userInput;
	coords player;
	if(!(menu.getRandomLevelStatus())){
		for(int i = 1; i<=map.getNumberOfMaps(); i++){
			map.loadMap(i);
			map.printMap(map.getMap(), &dict);
			while(true){
				if(map.checkWiningStatus()){
					break;
				}
				player = map.getPlayerCoords();

				#if defined(_WIN32)
					userInput = getch();
				#elif (defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__))
					cin>>userInput;
				#endif

				if(userInput >= 97){
					userInput-=32;
				}
				map.executeMove(player.x, player.y, map.getMap(), userInput);
				map.printMap(map.getMap(), &dict);
				if(map.checkWiningStatus()){
					break;
				}
			}
		}
	}
	else{
		while(true){
			map.loadRandomMap();
			map.printMap(map.getMap(), &dict);
			while(true){
				if(map.checkWiningStatus()){
					break;
				}
				player = map.getPlayerCoords();
				#if defined(_WIN32)
					userInput = getch();
				#elif (defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__))
					cin>>userInput;
				#endif
				if(userInput >= 97){
					userInput-=32;
				}
				map.executeMove(player.x, player.y, map.getMap(), userInput);
				map.printMap(map.getMap(), &dict);
				if(map.checkWiningStatus()){
					break;
				}
			}
		}
	}
	
	return 0;
}