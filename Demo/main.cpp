#include "../Engine/MagEngine.h"

#include "Game.h"
#include "../Engine/MagEngine.h"

#include <iostream>

int main()
{
	//Game::getInstance()->run();

	std::cout << "Start main" << std::endl;

	MagEngine::GameActor* actor = new MagEngine::GameActor("Temp");
	actor->addComponent(MagEngine::CAMERA);

	MagEngine::Component* camera = actor->getComponent(MagEngine::CAMERA);
	std::cout << "Actor " << actor->getName() << " now has camera: " << camera->getName() << std::endl;

	return 0;
}
