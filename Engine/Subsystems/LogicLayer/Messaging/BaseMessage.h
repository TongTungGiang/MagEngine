#ifndef BASEMESSAGE_H
#define BASEMESSAGE_H

namespace MagEngine
{

enum MessageType
{
};

/***
 *
 * BaseMessage
 *
 * Base class for all messages those can be sent.
 *
 */
class BaseMessage
{

public:

	BaseMessage(MessageType messageType);

	MessageType messageType;

protected:

	virtual ~BaseMessage() {}

};

}

#endif // BASEMESSAGE_H
