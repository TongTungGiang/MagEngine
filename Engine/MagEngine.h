#ifndef MAGENGINE_H
#define MAGENGINE_H

#include <vector>

#include "Subsystem.h"
#include "GameActor.h"

namespace MagEngine
{

/***
 *
 * MagEngine
 *
 * The engine class
 *
 */
class MagEngine
{

public:

	// Constructor
	MagEngine();

	// Main loop function
	void mainLoop();

private:

	std::vector<Subsystem> systems;


};

}

#endif // MAGENGINE_H
