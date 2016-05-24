#ifndef IEVENT_H
#define IEVENT_H

#include <string>
#include "IEventSender.h"

namespace MagEngine
{

/***
 *
 * BaseMessage
 *
 * Base interface for all messages those can be sent.
 *
 */
template<class S> // template for event sender classes
class IEvent
{

public:

	// Returns the type of the event
	virtual const std::string& getEventType() const = 0;

	// Returns the sender who sent this event
	virtual const S* getSender() const = 0;

	virtual void setSender(S* sender) const = 0;

};

}

#endif // IEVENT_H
