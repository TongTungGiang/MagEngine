#ifndef GAME_H
#define GAME_H

#include <OGRE/Ogre.h>
#include <OGRE/OgreSceneManager.h>
#include <OIS/OIS.h>

class Game : public Ogre::FrameListener
{

private:

	Game();
	~Game();

	static Game *instance;

	Ogre::Root *ogreRoot;
	Ogre::RenderWindow *window;
	Ogre::Camera *camera;
	Ogre::SceneManager *sceneManager;
	Ogre::Viewport *viewport;

public:

	static void destroyInstance();

	static Game *getInstance();

	void run();

	void createWindow();
	void createSceneManager();
	void createViewport();
	void createCamera();

	void setupResourceManager();
	
protected:
	
	bool frameStarted(const Ogre::FrameEvent &fe);
	
	bool frameEnded(const Ogre::FrameEvent &fe);
	
private:
	
	OIS::Mouse *mouse;
	OIS::Keyboard *keyboard;
	OIS::InputManager *inputManager;
	
private:
	
	void createInput();
	void destroyInput();
	void captureInput();
	

};

#endif // GAME_H
