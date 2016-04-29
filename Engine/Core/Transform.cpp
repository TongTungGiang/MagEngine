#include "Transform.h"
#include "GameActor.h"

namespace MagEngine
{

Transform::Transform(GameActor* owner)
    : Object(), owner(owner)
{
	std::cout << "Create transform: " << getName() << " owner = " << owner->getName() << std::endl;
	this->name.append("_Transform");
}

Transform::Transform(const std::string &name, GameActor* owner)
    : Object(name), owner(owner)
{
	std::cout << "Create transform: " << getName() << " owner = " << owner->getName() << std::endl;
	this->name.append("_Transform");
}

GameActor* Transform::getOwner()
{
	return owner;
}

}
