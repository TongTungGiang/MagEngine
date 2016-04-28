#include "../Engine/MagEngine.h"

#include "Game.h"
#include "../Engine/MagEngine.h"

#include <iostream>

int main()
{
	//Game::getInstance()->run();

	std::cout << "Start main" << std::endl;

	MagEngine::GameActor* actor = new MagEngine::GameActor("Temp");

	return 0;
}
