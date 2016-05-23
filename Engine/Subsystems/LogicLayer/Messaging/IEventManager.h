#ifndef IEVENTMANAGER_H
#define IEVENTMANAGER_H

#include "IBaseEvent.h"

namespace MagEngine
{

/***
 *
 * IEventManager
 *
 * The interface that define base behaviors of every event manager in the engine
 *
 */
class IEventManager
{

public:

	// Registers a delegate function that will get called when the event type is triggered.
	// Returns true if successful, false if not
	virtual bool addListener() = 0;

	// Removes a delegate - event type pairing. Retursn false if the pairing was not found
	virtual bool removeListener() = 0;

	// Fires off event
	virtual bool triggerEvent() = 0;

	// Singleton getter function
	static IEventManager* get() = 0;

};

}

#endif // IEVENTMANAGER_H
