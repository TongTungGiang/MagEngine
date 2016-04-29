#include "GameActor.h"

namespace MagEngine
{

GameActor::GameActor()
    : Object()
{
    transform = new Transform(this);

	std::cout << "Create game actor: " << getName() << " with " << components.size() << " components" << std::endl;
}

GameActor::GameActor(const std::string &name)
    : Object(name)
{
    transform = new Transform(name, this);
	std::cout << "Create game actor: " << getName() << " with " << components.size() << " components"<< std::endl;
}

Transform* GameActor::getTransform()
{
    return transform;
}

void GameActor::setName(const std::string &name)
{
    this->name = name;
    transform->setName(name);
}

Component* GameActor::getComponent(ComponentType type)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->isOfType(type))
			return components[i];
	}
}

std::vector<Component*> GameActor::getComponents(ComponentType type)
{
	std::vector<Component*> result;

	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->isOfType(type))
			result.push_back(components[i]);
	}

	return result;
}

Component* GameActor::addComponent(ComponentType type)
{
	Component* newComponent = ComponentFactory::createComponent(this, type);
	components.push_back(newComponent);

	return newComponent;
}

}
