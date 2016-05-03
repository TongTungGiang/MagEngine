#ifndef GAMESTATE_H
#define GAMESTATE_H

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

	GameState();

	virtual void update() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

};

}

#endif // GAMESTATE_H
