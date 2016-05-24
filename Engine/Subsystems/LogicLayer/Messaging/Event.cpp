#include "Event.h"

#include <iostream>

namespace MagEngine
{

template<class S> // template for event sender classes
Event<S>::Event()
{
	if (!std::is_base_of<IEventSender, S>::value)
	{
		std::cout << "Failed to create Event object" << std::endl;
		return;
	}

	sender = NULL;
}

template<class S> // template for event sender classes
Event<S>::~Event()
{
	delete sender;
}

template<class S> // template for event sender classes
void Event<S>::setSender(S* sender) const
{
	if (!std::is_base_of<IEventSender, S>::value)
	{
		return;
	}

	this->sender = sender;
}

template<class S> // template for event sender classes
const S* Event<S>::getSender() const
{
	return sender;
}

}
