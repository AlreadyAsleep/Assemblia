// textRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "Functions.h"




int main()
{
	//srand(time(NULL));

	Game game;
	game.initGame();

	/*
	Inventory inv;
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());
	inv.addItem(Item());

	inv.debugPrint();
	*/
	while (game.getPlaying())
	{
		game.mainMenu();
	}//while
    return 0;
}

