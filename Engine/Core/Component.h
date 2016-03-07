#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"

namespace MagEngine
{

    /* ----
     * Base class of everything that can be attached to a Game Object
     */
    class Component : public Object
    {

    public:

		Component();
		Component(const std::string &name);

    };
}

#endif // COMPONENT_H
