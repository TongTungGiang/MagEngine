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

    virtual ~InputSystem();

    void initialise(Ogre::RenderWindow *renderWindow);
    void capture();

    void addKeyListener(OIS::KeyListener *keyListener, const std::string& instanceName);
    void addMouseListener(OIS::MouseListener *mouseListener, const std::string& instanceName);

    void removeKeyListener(const std::string& instanceName);
    void removeMouseListener(const std::string& instanceName);

    void removeKeyListener(OIS::KeyListener *keyListener);
    void removeMouseListener(OIS::MouseListener *mouseListener);

    void removeAllListeners();
    void removeAllKeyListeners();
    void removeAllMouseListeners();

    void setWindowExtents(int width, int height);

    Mouse*    getMouse();
    Keyboard* getKeyboard();

    static InputSystem* getSingletonPtr();

private:

    InputSystem();
    InputSystem(const InputSystem&) { }
    InputSystem& operator = (const InputSystem&);

    bool keyPressed(const OIS::KeyEvent &e);
    bool keyReleased(const OIS::KeyEvent &e);

    bool mouseMoved(const OIS::MouseEvent &e);
    bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
    bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);

    OIS::Mouse *mouse;
    OIS::Keyboard *keyboard;
    OIS::InputManager *ogreInputManager;

    std::map<std::string, OIS::KeyListener*> mKeyListeners;
    std::map<std::string, OIS::MouseListener*> mMouseListeners;

    std::map<std::string, OIS::KeyListener*>::iterator itKeyListener;
    std::map<std::string, OIS::MouseListener*>::iterator itMouseListener;

    std::map<std::string, OIS::KeyListener*>::iterator itKeyListenerEnd;
    std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd;

    static InputSystem *inputSystem;

};

}

#endif // INPUTSYSTEM_H
