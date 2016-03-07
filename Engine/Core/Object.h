#ifndef OBJECT_H
#define OBJECT_H

#include <string>

namespace MagEngine
{

	/* ----
	 * Base class of all Game Object, Component classes
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
		std::string getName();
		int getUniqueID();

		// Set functions
		void setName(const std::string &name);

    };

}

#endif // OBJECT_H
