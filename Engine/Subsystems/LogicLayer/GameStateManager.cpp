#include "GameStateManager.h"

namespace MagEngine
{

GameStateManager::GameStateManager()
{
	gameStates();
}

void GameStateManager::pushState(GameState* state)
{
	gameStates.push_back(state);
	gameStates.back()->onEnter();
}

void GameStateManager::popState()
{
	if (!gameStates.empty())
	{
		if (gameStates.back()->onExit());
		{
			GameState* temp = gameStates.back();
			gameStates.pop_back();
			delete temp;
		}
	}
}

void GameStateManager::changeState(GameState* state)
{
	if (!gameStates.empty())
	{
		if (gameStates.back()->getStateID() == state->getStateID())
		{
			return;
		}

		if (gameStates.back()->onExit())
			popState();
	}
	pushState(state);
}

}
