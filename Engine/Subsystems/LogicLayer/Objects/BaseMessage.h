#ifndef IBASEMESSAGE_H
#define IBASEMESSAGE_H

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

};

}

#endif // IBASEMESSAGE_H
