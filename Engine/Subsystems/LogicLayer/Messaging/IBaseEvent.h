#ifndef BASEEVENT_H
#define BASEEVENT_H

#include <string>

namespace MagEngine
{

enum EventType
{
};

/***
 *
 * BaseMessage
 *
 * Base interface for all messages those can be sent.
 *
 */
class IBaseEvent
{

public:

	// Returns the type of the event
	virtual const EventType& getEventType() const = 0;

	// Returns the name of the event
	virtual const std::string& getName() const = 0;

};

}

#endif // BASEEVENT_H
