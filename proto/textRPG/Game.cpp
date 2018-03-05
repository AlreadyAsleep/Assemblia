#include "stdafx.h"
#include "Game.h"




Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "characters.txt";

	
}


Game::~Game()
{
	
}

//Functions
void Game::initGame()
{
	createNewCharacter();
}//initGame

void Game::mainMenu()
{
	cout << "MAIN MENU" << endl;

	cout << "0 Quit" << endl;
	cout << "1 Travel" << endl;
	cout << "2 Shop" << endl;
	cout << "3 Level up" << endl;
	cout << "4 Rest" << endl;
	cout << "5 Character sheet" << endl;
	cout << "6 Create new character" << endl;
	cout << "7 Save character" << endl;
	cout << endl;

	cout << endl << "Choice:";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 0:
		playing = false;
		break;
	case 5:
		characters[activeCharacter].printStats();
		break;
	case 6:
		std::cin.ignore();
		createNewCharacter();
		saveCharacters();
		break;
	case 7:
		saveCharacters();
		break;
	case 8:
		loadCharacters();
		break;
	default:
		break;

	}//switch
}

void Game::createNewCharacter()
{
	
	std::string name;
	std::cout << "Enter name for character: ";
	

	getline(std::cin, name);
	

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}//createNewCharacter

void Game::saveCharacters()
{
	std::ofstream outFile(fileName);
	if(outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString()<< "\n";
		}//for
	}//if

	outFile.close();
}//saveCharacters
void Game::loadCharacters()
{

}//loadCharacters