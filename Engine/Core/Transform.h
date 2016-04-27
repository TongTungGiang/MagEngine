#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Object.h"
#include "Ogre.h"

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
 * Transform
 *
 * Composed of Scale, Rotation, and Position of the GameActor
 *
 */
class Transform : public Object
{

public:

	// Constructors and destructors
    Transform();
    Transform(const std::string &name);

    // Getter functions
	GameActor* getOwner();

    // Setter functions

private:

    Ogre::SceneNode* sceneNode;

	GameActor* owner;

};

}

#endif // TRANSFORM_H
