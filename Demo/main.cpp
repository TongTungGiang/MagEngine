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

    std::vector<MagEngine::Component*> cameras = actor->getComponents(MagEngine::CAMERA);
    std::cout << "Actor " << actor->getName() << " has " << cameras.size() << " cameras" << std::endl;

	return 0;
}
