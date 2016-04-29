#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"
#include "ComponentType.h"

#include <vector>

namespace MagEngine
{

// -----
// Forward declarations

/***
 * GameActor
 *
 * The base class of an Object that can be placed or spawned in a level.
 * A GameActor may contain some Component instances which define its appearance, behavior and functionality.
 *
 */
class GameActor;

	// End Forward declaration
// -----


/***
 *
 * Component
 *
 * Base class of everything that can be attached to a Game Object
 *
 */
class Component : public Object
{

protected:

	// Every component has an owner of type GameActor
	GameActor* owner;

	// A component may have many tags - for example, a mesh renderer is a renderer, so it has 'Renderer' and 'Mesh Renderer' tag at once
	std::vector<ComponentType> componentTags;

	// Add a new tag to the component
	void addTag(ComponentType newTag);

public:

	// Constructors and Destructors
    Component(GameActor* owner);
    Component(const std::string &name, GameActor* owner);
	~Component();

	// Check if the component has the desired tag or not
	bool isOfType(ComponentType type);

};

}

#endif // COMPONENT_H
