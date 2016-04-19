#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Object.h"
#include "Ogre.h"

namespace MagEngine
{

class Transform : public Object
{

public:

    Transform();
    Transform(const std::string &name);

    // Getter functions


    // Setter functions

private:

    Ogre::SceneNode* sceneNode;

};

}

#endif // TRANSFORM_H
