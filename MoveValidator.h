#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H
#include <vector>
#include <string>


class MoveValidator{
	public:
		MoveValidator(int mapHeight, int mapLength);
		bool validateRightMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map);
		bool validateLeftMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map);
		bool validateDownMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map);
		bool validateUpMove(int xCoords, int yCoords, const std::vector<std::vector<std::string>> &map);
	private:
		int mapHeight;
		int mapLength;
};

#endif