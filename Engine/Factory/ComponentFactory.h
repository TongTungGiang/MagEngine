#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "../Core/Component.h"

#include <map>

namespace MagEngine
{

/***
 *
 * ComponentFactory
 *
 * Base class of all factory classes those are responsible of creating components
 *
 */
class ComponentFactory
{

	// Factory method
	virtual Component* create() = 0;

	// The map of factory objects
	static std::map<ComponentType, ComponentFactory*> factories;

public:

	// Constructor and Destructors
	ComponentFactory();
	virtual ~ComponentFactory() {}

	friend class ComponentFactoryInitializer;

	static Component* createComponent(ComponentType id);

};

}
#endif // COMPONENTFACTORY_H
