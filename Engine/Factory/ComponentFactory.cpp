#include "ComponentFactory.h"

namespace MagEngine
{
// Define the static object
std::map<ComponentType, ComponentFactory*> ComponentFactory::factories;

ComponentFactory::ComponentFactory()
{
}

Component* ComponentFactory::createComponent(ComponentType id)
{
	if (factories.find(id) != factories	.end())
		return factories[id]->create();
}

}
