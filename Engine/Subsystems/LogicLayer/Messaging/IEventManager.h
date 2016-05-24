#ifndef IEVENTMANAGER_H
#define IEVENTMANAGER_H

#include "IBaseEvent.h"
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
class IEventManager
{

public:

	// Registers a delegate function that will get called when the event type is triggered.
	// Returns true if successful, false if not
	template<class E> // template for event classes
	template<class D> // template for delegate classes
	virtual bool addListener(const E* event, const D* eventDelegate) = 0;

	// Removes a delegate - event type pairing. Returns false if the pairing was not found
	template<class E> // template for event classes
	template<class D> // template for delegate classes
	virtual bool removeListener(const E* event, const D* eventDelegate) = 0;

	// Fires off event
	virtual bool triggerEvent() = 0;

	// Singleton getter function
	virtual static IEventManager* get() = 0;

};

}

#endif // IEVENTMANAGER_H
