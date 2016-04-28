#ifndef COMPONENTFACTORYINITIALIZER_H
#define COMPONENTFACTORYINITIALIZER_H

#include "ComponentFactory.h"

namespace MagEngine
{

/***
 *
 * ComponentFactoryInitializer
 *
 * Initializer for Component Factory - singleton
 *
 */
class ComponentFactoryInitializer
{

	static ComponentFactoryInitializer instance;

	ComponentFactoryInitializer();

};

}

#endif // COMPONENTFACTORYINITIALIZER_H
