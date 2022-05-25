#include <iostream>
#include "MoveValidator.h"

using namespace std;

MoveValidator::MoveValidator(int _mapHeight, int _mapLength){
	MoveValidator::mapHeight = _mapHeight;
	MoveValidator::mapLength= _mapLength;
}

bool MoveValidator::validateRightMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map){
	if(map[yCoords][xCoords+1] == "E" or map[yCoords][xCoords+1] == "H") return true;
	else if(xCoords <= MoveValidator::mapLength-2){
		if(map[yCoords][xCoords+1] == "B" and (map[yCoords][xCoords+2] == "E" or map[yCoords][xCoords+2] == "H")){
			return true;
		}
	}
	return false;
}

bool MoveValidator::validateLeftMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map){
	if(map[yCoords][xCoords-1] == "E" or map[yCoords][xCoords-1] == "H") return true;
	else if(xCoords >= 2){
		if(map[yCoords][xCoords-1] == "B" and (map[yCoords][xCoords-2] == "E" or map[yCoords][xCoords-2] == "H")){
			return true;
		}
	}
	return false;
}

bool MoveValidator::validateDownMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map){
	if(map[yCoords+1][xCoords] == "E" or map[yCoords+1][xCoords] == "H") return true;
	else if(yCoords <= MoveValidator::mapHeight-2){
		if(map[yCoords+1][xCoords] == "B" and (map[yCoords+2][xCoords] == "E" or map[yCoords+2][xCoords] == "H")){
			return true;
		}
	}
	return false;
}

bool MoveValidator::validateUpMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map){
	if(map[yCoords-1][xCoords] == "E" or map[yCoords-1][xCoords] == "H") return true;
	else if(yCoords >= 2){
		if(map[yCoords-1][xCoords] == "B" and (map[yCoords-2][xCoords] == "E" or map[yCoords-2][xCoords] == "H")){
			return true;
		}
	}
	return false;
}