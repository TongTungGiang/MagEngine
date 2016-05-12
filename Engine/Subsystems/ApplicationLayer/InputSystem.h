#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISJoyStick.h>
#include <OISInputManager.h>

#include <OgreRenderWindow.h>

namespace MagEngine
{

typedef Mouse OIS::Mouse;
typedef Keyboard OIS::Keyboard;

class InputSystem :public OIS::KeyListener, public OIS::MouseListener, public OIS::JoyStickListener
{

public:

    InputSystem();

};

}

#endif // INPUTSYSTEM_H
