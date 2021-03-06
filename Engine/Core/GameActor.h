#ifndef GAMEACTOR_H
#define GAMEACTOR_H

#include "Object.h"
#include "Transform.h"
#include "Component.h"

#include "ComponentFactory.h"

#include <vector>

namespace MagEngine
{

/***
 * GameActor
 *
 * The base class of an Object that can be placed or spawned in a level.
 * A GameActor may contain some Component instances which define its appearance, behavior and functionality.
 *
 */
class GameActor : public Object
{

public:

    // Constructors and Destructors
    GameActor();
    GameActor(const std::string &name);

    // Get transform information of the Game Actor
    Transform* getTransform();

	// Get first component of type
	Component* getComponent(ComponentType type);

	// Get components of type
	std::vector<Component*> getComponents(ComponentType type);

	// Add new component to the game object
	Component* addComponent(ComponentType type);

    // Setter functions
    virtual void setName(const std::string &name);

private:

    // Transform - specify game object's position, rotation, scale as well as child-parent relationships
    Transform* transform;

	// Components - a game object is generic and contains some components which define its behavior, functionality and appearance
	std::vector<Component*> components;

};

}

#endif // GAMEACTOR_H
