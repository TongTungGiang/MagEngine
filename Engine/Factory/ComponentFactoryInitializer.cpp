#include "ComponentFactoryInitializer.h"

#include "../Components/Camera/Camera.h"

namespace MagEngine
{

// Define static member
ComponentFactoryInitializer ComponentFactoryInitializer::instance;

ComponentFactoryInitializer::ComponentFactoryInitializer()
{
	ComponentFactory::factories[CAMERA] = new Camera::Factory;
}

}
