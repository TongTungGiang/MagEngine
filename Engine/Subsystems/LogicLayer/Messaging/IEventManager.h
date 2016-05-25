#ifndef IEVENTMANAGER_H
#define IEVENTMANAGER_H

#include "IEvent.h"
#include "IEventListenerDelegate.h"

namespace MagEngine
{

/***
 *
 * IEventManager
 *
 * The interface that define base behaviors of every event manager in the engine
 *
 */
template<class E, class D>
class IEventManager
{

public:

	// Registers a delegate function that will get called when the event type is triggered.
	// Returns true if successful, false if not
	virtual bool addListener(const E* event, const D* eventDelegate) = 0;

	// Removes a delegate - event type pairing. Returns false if the pairing was not found
	virtual bool removeListener(const E* event, const D* eventDelegate) = 0;

	// Fires off event immediately
	virtual bool triggerEvent(E* event) = 0;

	// Fires off event by putting it into the currently active queue
	virtual bool queueEvent(E* event) = 0;

};

}

#endif // IEVENTMANAGER_H
