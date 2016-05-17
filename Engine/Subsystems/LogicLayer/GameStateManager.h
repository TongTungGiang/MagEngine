#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "Subsystem.h"
#include "GameState.h"

#include <vector>

namespace MagEngine
{

/***
 *
 * Game StateManager
 *
 * Manage game states:
 * - Push: add a new state to stack.
 * - Change: add a new state to stack and that new state will replace the current state
 * - Pop: remove current state.
 *
 */
class GameStateManager : Subsystem
{

public:

	// Constructor
	GameStateManager();

	// Add a new state to stack
	void pushState(GameState* state);

	// Add a new state to stack and replace the current state
	void changeState(GameState* state);

	// Remove current state
	void popState();

private:

	std::vector<GameState*> gameStates;

};

}

#endif // GAMESTATEMANAGER_H
