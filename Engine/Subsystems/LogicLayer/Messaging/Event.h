#ifndef EVENT_H
#define EVENT_H

#include "IEvent.h"
#include "IEventSender.h"
#include <type_traits>

namespace MagEngine
{

template<class S> // template for event sender classes
class Event : public IEvent<S>
{

public:

	Event();

	virtual ~Event();

	virtual const std::string& getEventType() const;

	virtual const S* getSender() const;

	virtual void setSender(S *sender) const;

private:

	S* sender;

};

}

#endif // EVENT_H
