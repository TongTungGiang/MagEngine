#include "Camera.h"

namespace MagEngine
{

Camera::Camera(GameActor* owner)
	: Component(owner)
{
	addTag(CAMERA);
	this->name.append("_Camera");
}

Camera::Camera(const std::string &name, GameActor *owner)
	: Component(name, owner)
{
	addTag(CAMERA);
	this->name.append("_Camera");
}

// Factory method
Component* Camera::Factory::create(GameActor* owner)
{
	Camera* comp;
	comp = new Camera(owner->getName(), owner);

	return comp;
}

}