#include "Object.h"

namespace MagEngine
{
Object::Object()
{
    static int ID = 0;
    uniqueID = ++ID;
    name = "";
}

Object::Object(const std::string &name)
    : name(name)
{
    static int ID = 0;
    uniqueID = ++ID;
}

const std::string& Object::getName()
{
    return name;
}

int Object::getUniqueID()
{
    return uniqueID;
}

void Object::setName(const std::string &name)
{
    this->name = name;
}

}

