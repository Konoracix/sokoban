#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <fstream>
#include "MapController.h"
#include "MoveValidator.h" 

using namespace std;

MapController::MapController(int _mapLength, int _mapHeight, int _numberOfMaps){
	MapController::mapHeight = _mapHeight;
	MapController::mapLength = _mapLength;
	MapController::moveValidator = new MoveValidator(_mapHeight, _mapLength);
	MapController::numberOfMaps = _numberOfMaps;
}

MapController::~MapController(){
	delete MapController::moveValidator;
}

void MapController::executeMove(int xCoords, int yCoords, const vector<vector<string>> &map, char direction){
	switch (direction)
	{
	case 'W':
		if(moveValidator->validateUpMove(xCoords, yCoords, map)){
			MapController::executeUpDirectionMove(xCoords, yCoords, map);
		}
		break;
	case 'D':
		if(moveValidator->validateRightMove(xCoords, yCoords, map)){
			MapController::executeRightDirectionMove(xCoords, yCoords, map);
		}
		break;
	case 'A':
		if(moveValidator->validateLeftMove(xCoords, yCoords, map)){
			MapController::executeLeftDirectionMove(xCoords, yCoords, map);
		}
		break;
	case 'S':
		if(moveValidator->validateDownMove(xCoords, yCoords, map)){
			MapController::executeDownDirectionMove(xCoords, yCoords, map);
		}
		break;
	
	default:
		break;
	}
}

void MapController::loadRandomMap(void){
	srand(time(NULL));
	MapController::loadMap((rand()%MapController::numberOfMaps)+1);
}

void MapController::loadMap(int mapNumber){
	string fileName = "./maps/map" + to_string(mapNumber) + ".txt";
	ifstream mapFile(fileName);
	string line = "";
	string element = "";
	int pointsRequireds;
	if(mapFile){
		vector<vector<string>> map;
		vector<string> fileLine;
		for(int i = 0; i<mapHeight; i++){
			getline(mapFile, line);
			istringstream iss(line);
			for(int j = 0; j<mapLength; j++){
				iss >> element;
				fileLine.push_back(element);  
			}
			map.push_back(fileLine);
			fileLine.clear();
		}
		MapController::mapPattern = map;
		map.clear();
		fileLine.	clear();
		for(int i = 0; i<mapHeight; i++){
			getline(mapFile, line);
			istringstream iss(line);
			for(int j = 0; j<mapLength; j++){
				iss >> element;
				fileLine.push_back(element);  
			}
			map.push_back(fileLine);
			fileLine.clear();
		}
		MapController::map = map;
		mapFile>>pointsRequired;
		MapController::pointsRequired = pointsRequired;
		return;
	}
	MapController::mapPattern = vector<vector<string>>(0);
	
	return;
}

void MapController::printMap(const std::vector<std::vector<std::string>> &map, Dictionary* dictionary){
	string box = dictionary->getBox();
	string player = dictionary->getPlayer();
	string rescuePoint = dictionary->getRescuePoint();
	string wall = dictionary->getWall();

	#if defined(_WIN32)
		system("cls");
	#elif (defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__))			
		system("clear");
	#endif
	
	for(auto x : map){
		for(std::string y : x){
			if(y == "W"){
				cout << wall;
			} else if(y == "B"){
				cout << box;
			} else if(y == "H"){
				cout << rescuePoint;
			} else if(y == "P"){
				cout << player;
			} else if(y == "E"){
				cout << " "; 
			}
		}
		cout << endl;
	}
}

std::vector<std::vector<std::string>> MapController::getMapPattern(){
	return MapController::mapPattern;
}

std::vector<std::vector<std::string>> MapController::getMap(){
	return MapController::map;
}

int MapController::getMapHeight(){
	return MapController::mapHeight;
}

int MapController::getMapLength(){
	return MapController::mapLength;
}

void MapController::executeUpDirectionMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map){
	if(MapController::map[yCoords-1][xCoords] == "E" or MapController::map[yCoords-1][xCoords] == "H"){
		MapController::map[yCoords-1][xCoords] = "P";
		MapController::map[yCoords][xCoords] = MapController::mapPattern[yCoords][xCoords];
	}
	else if(MapController::map[yCoords-1][xCoords] == "B"){
		MapController::map[yCoords-1][xCoords] = "P";
		MapController::map[yCoords-2][xCoords] = "B";
		MapController::map[yCoords][xCoords] = MapController::mapPattern[yCoords][xCoords];
	}
}

void MapController::executeRightDirectionMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map){
	if(MapController::map[yCoords][xCoords+1] == "E" or MapController::map[yCoords][xCoords+1] == "H"){
		MapController::map[yCoords][xCoords+1] = "P";
		MapController::map[yCoords][xCoords] = MapController::mapPattern[yCoords][xCoords];
	}
	else if(MapController::map[yCoords][xCoords+1] == "B"){
		MapController::map[yCoords][xCoords+1] = "P";
		MapController::map[yCoords][xCoords+2] = "B";
		MapController::map[yCoords][xCoords] = MapController::mapPattern[yCoords][xCoords];
	}
}

void MapController::executeLeftDirectionMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map){
	if(MapController::map[yCoords][xCoords-1] == "E" or MapController::map[yCoords][xCoords-1] == "H"){
		MapController::map[yCoords][xCoords-1] = "P";
		MapController::map[yCoords][xCoords] = MapController::mapPattern[yCoords][xCoords];
	}
	else if(MapController::map[yCoords][xCoords-1] == "B"){
		MapController::map[yCoords][xCoords-1] = "P";
		MapController::map[yCoords][xCoords-2] = "B";
		MapController::map[yCoords][xCoords] = MapController::mapPattern[yCoords][xCoords];
	}
}

void MapController::executeDownDirectionMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map){
	if(MapController::map[yCoords+1][xCoords] == "E" or MapController::map[yCoords+1][xCoords] == "H"){
		MapController::map[yCoords+1][xCoords] = "P";
		MapController::map[yCoords][xCoords] = MapController::mapPattern[yCoords][xCoords];
	}
	else if(MapController::map[yCoords+1][xCoords] == "B"){
		MapController::map[yCoords+1][xCoords] = "P";
		MapController::map[yCoords+2][xCoords] = "B";
		MapController::map[yCoords][xCoords] = MapController::mapPattern[yCoords][xCoords];
	}
}

coords MapController::getPlayerCoords(){
	for(int y = 0; y<MapController::mapHeight; y++){
		for(int x = 0; x<MapController::mapLength; x++){
			if(MapController::map[y][x] == "P") return {x, y};
		}
	}
	return {0, 0};
}

bool MapController::checkWiningStatus(){
	for(int y = 0; y<MapController::mapHeight; y++){
		for(int x = 0; x<MapController::mapLength; x++){
			if(MapController::mapPattern[y][x] == "H"){
				if(MapController::map[y][x] != "B") return false;
			}
		}
	}
	return true;
}

int MapController::getNumberOfMaps(){
	return MapController::numberOfMaps;
}