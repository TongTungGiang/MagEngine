#include "GameState.h"

namespace MagEngine
{

int GameState::getNextStateID()
{
	return nextStateID;
}

int GameState::getStateID()
{
	return stateID;
}

void GameState::setNextStateID(int nextStateID)
{
	this->nextStateID = nextStateID;
}

}
