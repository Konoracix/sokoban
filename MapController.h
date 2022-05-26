#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H
#include <vector>
#include <string>
#include "Dictionary.h"
#include "MoveValidator.h" 

struct coords{
	int x;
	int y;
};

class MapController{
	public:
		MapController(int mapLength, int mapHeight);
		~MapController();
		void loadRandomMap(void);
		void loadMap(int mapNumber);
		void printMap(const std::vector<std::vector<std::string>> &map, Dictionary* dictionary);
		std::vector<std::vector<std::string>> getMapPattern();
		std::vector<std::vector<std::string>> getMap();
		int getMapLength();
		int getMapHeight();
		MoveValidator* moveValidator;
		void executeMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map, char direction);
		void executeRightDirectionMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map);
		void executeLeftDirectionMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map);
		void executeUpDirectionMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map);
		void executeDownDirectionMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map);
		coords getPlayerCoords();
		bool checkWiningStatus(void);
		int getNumberOfMaps(void);
	private:
		std::vector<std::vector<std::string>> mapPattern;
		std::vector<std::vector<std::string>> map;
		int mapLength;
		int mapHeight;
		int pointsRequired;
		int numberOfMaps;
};

#endif // MAPCONTROLLER_H