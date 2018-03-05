#pragma once
#include "functions.h"
#include "Character.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

class Game
{
private:
	int choice;
	bool playing;

	//character related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;



public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void saveCharacters();
	void loadCharacters();

	//Accessors
	inline bool getPlaying() const { return this->playing; }
	//Modifiers

	


};

