#include "Component.h"

namespace MagEngine
{
    Component::Component()
		: Object()
    {
    }

    Component::Component(const std::string &name)
		: Object(name)
    {
    }

}
