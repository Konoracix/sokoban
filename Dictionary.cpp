#include <iostream>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary(bool colorModeEnabled){
	if(colorModeEnabled){
		Dictionary::box = "\033[31;1m#\033[0m";
		Dictionary::rescuePoint = "\033[1;32mH\033[0m";
		Dictionary::wall = "\033[90m#\033[0m";
		Dictionary::player = "\33[34mo\33[0m";
	}
	else{
		Dictionary::box = "x";
		Dictionary::rescuePoint = "H";
		Dictionary::wall = "#";
		Dictionary::player = "o";
	}
}

string Dictionary::getWall(){
	return wall;
}
string Dictionary::getPlayer(){
	return player;
}
string Dictionary::getRescuePoint(){
	return rescuePoint;
}
string Dictionary::getBox(){
	return box;
}