#ifndef IEVENTLISTENERDELEGATE_H
#define IEVENTLISTENERDELEGATE_H

namespace MagEngine
{

/***
 *
 * EventListenerDelegate
 *
 * Events and event data need to go to event listener delegate functions.
 * A delegate function is called when an event is fired.
 *
 */
template<class E>
class IEventListenerDelegate
{

public:

	// How the listener handle the event
	virtual void handleEvent(E* event) = 0;

	IEventListenerDelegate();

	virtual ~IEventListenerDelegate();

};

}

#endif // IEVENTLISTENERDELEGATE_H
