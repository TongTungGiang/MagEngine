#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <list>
#include <map>
#include <type_traits>

#include "IEvent.h"
#include "IEventListenerDelegate.h"
#include "IEventManager.h"

// The number of event queues.
// There are two event queue so that delegate functions can
// safely queue up new events.
#define EVENT_MANAGER_NUM_QUEUES 2

namespace MagEngine
{

/***
 *
 * EventManager
 *
 * Base class of every event manger
 *
 */
template<class E, class D>
class EventManager : public IEventManager <E, D>
{

public:

	// Constructor
	EventManager();

	// Registers a delegate function that will get called when the event type is triggered.
	// Returns true if successful, false if not
	virtual bool addListener(const std::string& eventType, const D* eventDelegate);

	// Removes a delegate - event type pairing. Returns false if the pairing was not found
	virtual bool removeListener(const std::string& eventType, const D* eventDelegate);

	// Fires off event immediately
	virtual bool triggerEvent(E* event);

	// Fires off event by putting it into the currently active queue
	virtual bool queueEvent(E* event);

	// Update is called every frame
	virtual void update();

private:

	//---
	// typedef region
	typedef std::list<IEventListenerDelegate<E>> EventListenerList;
	typedef std::map<std::string, EventListenerList> EventListenerMap;
	typedef std::list<IEvent<D>*> EventQueue;
	// end typedef region
	//---

	// The map of event listeners: each event has a list of delegates to call
	// when the event is triggered
	EventListenerMap eventListeners;

	// Two event queues
	EventQueue queues[EVENT_MANAGER_NUM_QUEUES];

	// The currently active queue
	int activeQueue;

};

}

#endif // EVENTMANAGER_H
