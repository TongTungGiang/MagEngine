#include "InputSystem.h"

namespace MagEngine
{

InputSystem::InputSystem()
{
}

InputSystem& InputSystem::operator = (const InputSystem&)
{
}

bool InputSystem::keyPressed(const OIS::KeyEvent &e)
{
}

bool InputSystem::keyReleased(const OIS::KeyEvent &e)
{
}

bool InputSystem::mouseMoved(const OIS::MouseEvent &e)
{
}

bool InputSystem::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
}

bool InputSystem::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
}

}
