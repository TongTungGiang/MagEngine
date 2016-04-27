#include "Transform.h"
#include "GameActor.h"

namespace MagEngine
{

Transform::Transform()
    : Object()
{
}

Transform::Transform(const std::string &name)
    : Object(name)
{
}

GameActor* Transform::getOwner()
{
	return owner;
}

}
