#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <Ogre.h>

namespace MagEngine
{

/***
 *
 * GameState
 *
 * Splash screen, menu, main game,... are game states. This is the base class of every game state like such. It can take care of itself like load, render, update...
 *
 */
class GameState
{

public:

	virtual void update() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	int getNextStateID();
	int getStateID();

	void setNextStateID(int nextStateID);

protected:

	// Constructors
	GameState() {}

	int stateID;

private:

	int nextStateID;

};

}

#endif // GAMESTATE_H
