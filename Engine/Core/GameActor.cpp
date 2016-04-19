#include "GameActor.h"

namespace MagEngine
{

GameActor::GameActor()
    : Object()
{
    transform = new Transform();
}

GameActor::GameActor(const std::string &name)
    : Object(name)
{
    transform = new Transform(name);
}

Transform* GameActor::getTransform()
{
    return transform;
}

void GameActor::setName(const std::string &name)
{
    this->name = name;
    transform->setName(name);
}

}
