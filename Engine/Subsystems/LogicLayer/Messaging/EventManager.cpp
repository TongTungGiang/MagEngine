#include "EventManager.h"
#include <iostream>

namespace MagEngine
{

template<class E, class D>
EventManager<E, D>::EventManager()
{
	activeQueue = 0;
}

template<class E, class D>
bool EventManager<E, D>::addListener(const std::string& eventType, const D* eventDelegate)
{
	if (!std::is_base_of<IEventListenerDelegate<E>, D>::value)
	{
		std::cout << "D must be a subclass of IEventListenerDelegate!" << std::endl;
		return false;
	}

	// Check whether the coupling relationship is already existed or not
	EventListenerList& eventListenerList = eventListeners[eventType];
	for (auto itr = eventListenerList.begin();
		 itr != eventListenerList.end();
		 ++itr)
	{
		if (eventDelegate == (*itr))
		{
			std::cout << "The coupling relationship is already existed." << std::endl;
			return false;
		}
	}

	// Hooray, it is not existed!
	eventListenerList.push_back(eventDelegate);
	return true;
}

// STUCK HERE AS FUCK
template<class E, class D>
bool EventManager<E, D>::removeListener(const std::string& eventType, const D* eventDelegate)
{
	if (!std::is_base_of<IEventListenerDelegate<E>, D>::value)
	{
		std::cout << "D must be a subclass of IEventListenerDelegate!" << std::endl;
		return false;
	}

	bool success = false;

	return success;
}

template<class E, class D>
bool EventManager<E, D>::triggerEvent(E* event)
{
	bool processed = false;

	if (!std::is_base_of<IEvent<D>, E>::value)
	{
		std::cout << "E must be a subclass of IEvent!" << std::endl;
		return false;
	}

	auto findItr = eventListeners.find(event->getEventType());

	if (findItr == eventListeners.end())
	{
		std::cout << "Bad reference: no such type of event" << std::endl;
		return false;
	}

	const EventListenerList& eventListenerList = findItr->second;
	for (auto itr = eventListenerList.begin();
		 itr != eventListenerList.end();
		 ++itr)
	{
		IEventListenerDelegate<E>* listener = (*itr);
		listener->handleEvent(event);
		processed = true;
	}

	return processed;
}

template<class E, class D>
bool EventManager<E, D>::queueEvent(E* event)
{
	std::cout << "Queueing event..." << std::endl;
	if (!std::is_base_of<IEvent<D>, E>::value)
	{
		std::cout << "E must be a subclass of IEvent!" << std::endl;
		return false;
	}

	auto findItr = eventListeners.find(event->getEventType());

	if (findItr == eventListeners.end())
	{
		std::cout << "Bad reference: no such type of event" << std::endl;
		return false;
	}

	std::cout << "Event queued successfully" << std::endl;
	queues[activeQueue].push_back(event);
	return true;
}

}
