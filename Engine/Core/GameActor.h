#ifndef GAMEACTOR_H
#define GAMEACTOR_H

#include "Object.h"
#include "Transform.h"

namespace MagEngine
{

class GameActor : public Object
{

public:

    // Constructor
    GameActor();
    GameActor(const std::string &name);

    // Getter functions
    Transform* getTransform();

    // Setter functions
    virtual void setName(const std::string &name);

private:

    // Transform - specify game object's position, rotation, scale as well as child-parent relationships
    Transform* transform;

};

}

#endif // GAMEACTOR_H
