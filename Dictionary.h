#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>

class Dictionary{
	public:
		Dictionary(bool colorModeEnabled);
		std::string getWall();
		std::string getPlayer();
		std::string getRescuePoint();
		std::string getBox();
	private:
		std::string box;
		std::string player;
		std::string wall;
		std::string rescuePoint;

};

#endif