#include "Game.h"
#include"SpriteManager.h"
#include"Simon.h"
#include "Zombie.h"
#include"Camera.h"
#include"SweptAABB.h"
#include"GameStatus.h"
#include"GameStatus.h"

Game* Game::instance=0;

Game* Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

void Game::init()
{
	map = new Map("Data\\Map\\Map1\\matrix.txt", 
		"Data\\Map\\Map1\\tileSheet.png",
		"Data\\Map\\Map1\\allobject.txt",
		"Data\\Map\\Map1\\quadtree.txt",
		"Data\\Map\\Map1\\stages.txt");

}
void Game::update()
{
	map->update();
	GAMESTATUS->update();
}

void Game::draw()
{
	map->draw();
	GAMESTATUS->draw();
	SIMON->draw();
}

Game::Game()
{
}


Game::~Game()
{
}
