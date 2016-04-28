#include "Transform.h"
#include "GameActor.h"

namespace MagEngine
{

Transform::Transform(GameActor* owner)
    : Object(), owner(owner)
{
	std::cout << "Create transform: " << getName() << " owner = " << owner->getName() << std::endl;
}

Transform::Transform(const std::string &name, GameActor* owner)
    : Object(name), owner(owner)
{
	std::cout << "Create transform: " << getName() << " owner = " << owner->getName() << std::endl;
}

GameActor* Transform::getOwner()
{
	return owner;
}

}
