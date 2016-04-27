#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"

#include <vector>

namespace MagEngine
{

/***
 *
 * ComponentType
 *
 * The enum defines ID for component types
 *
 */
enum ComponentType
{
	// Renderer section
	RENDERER,

	// Nav mesh section
	NAVMESHAGENT,

	// Camera section
	CAMERA
};

/***
 *
 * Component
 *
 * Base class of everything that can be attached to a Game Object
 *
 */
class Component : public Object
{

private:

	// A component may have many tags - for example, a mesh renderer is a renderer, so it has 'Renderer' and 'Mesh Renderer' tag at once
	std::vector<ComponentType> componentTags;

protected:

	// Add a new tag to the component
	void addTag(ComponentType newTag);

public:

	// Constructors and Destructors
    Component();
    Component(const std::string &name);
	~Component();

	// Check if the component has the desired tag or not
	bool isOfType(ComponentType type);

};

}

#endif // COMPONENT_H
