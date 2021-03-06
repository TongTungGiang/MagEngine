#include "Component.h"
#include "GameActor.h"

#include <algorithm>

namespace MagEngine
{

Component::Component(GameActor* owner)
    : Object(), owner(owner)
{
}

Component::Component(const std::string &name, GameActor* owner)
    : Object(name), owner(owner)
{
}

Component::~Component()
{

}

void Component::addTag(ComponentType newTag)
{
	if (componentTags.empty())
	{
		componentTags.push_back(newTag);

		return;
	}

	// The component already has that newTag
	if (isOfType(newTag))
		return;

	componentTags.push_back(newTag);
}

bool Component::isOfType(ComponentType type)
{
	if (componentTags.empty())
		return false;

	if (std::find(componentTags.begin(), componentTags.end(), type) != componentTags.end())
		return true;

	return false;
}

}
