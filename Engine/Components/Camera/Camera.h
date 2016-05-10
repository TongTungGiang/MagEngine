#ifndef CAMERA_H
#define CAMERA_H

#include "Component.h"
#include "ComponentFactory.h"

namespace MagEngine
{

/***
 *
 * Camera
 *
 * Camera is the object through which the player view the scene.
 *
 */
class Camera : public Component
{

public:

	// Constructors and Destructors
	Camera(GameActor* owner);
	Camera(const std::string &name, GameActor* owner);
	~Camera() {}

	// Implement friend factory class
	class Factory;
	friend class Factory;
	class Factory : public ComponentFactory
	{

	public:

		virtual Component* create(GameActor* owner);

	};
	// End factory class

};

}

#endif // CAMERA_H
