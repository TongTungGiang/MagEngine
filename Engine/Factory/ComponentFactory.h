#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "Component.h"
#include "GameActor.h"

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
	virtual Component* create(GameActor* owner) = 0;

	// The map of factory objects
	static std::map<ComponentType, ComponentFactory*> factories;

public:

	// Constructor and Destructors
	ComponentFactory();
	virtual ~ComponentFactory() {}

	friend class ComponentFactoryInitializer;

	static Component* createComponent(GameActor* owner, ComponentType id);

};

}
#endif // COMPONENTFACTORY_H
