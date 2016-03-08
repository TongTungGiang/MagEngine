#ifndef GAMEACTOR_H
#define GAMEACTOR_H

#include "Object.h"

namespace MagEngine
{

	class GameActor : public Object
	{

	public:

		// Constructor
		GameActor();
		GameActor(const std::string &name);

	};

}

#endif // GAMEACTOR_H
