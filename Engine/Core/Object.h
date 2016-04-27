#ifndef OBJECT_H
#define OBJECT_H

#include <string>

namespace MagEngine
{

/***
 *
 * Object
 *
 * Base class of all GameActor, Component classes
 *
 */
class Object
{

protected:

    // Object's name
    std::string name;

    // Object's unique ID
    int uniqueID;

public:

    // Constructors
    Object();
    Object(const std::string &name);

    // Get functions
    const std::string& getName();
    int getUniqueID();

    // Set functions
    virtual void setName(const std::string &name);

};

}

#endif // OBJECT_H
