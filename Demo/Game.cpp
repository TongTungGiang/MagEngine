#include "Game.h"

Game *Game::instance = NULL;

Game* Game::getInstance()
{
	if (instance == NULL)
		instance = new Game();

	return instance;
}

void Game::destroyInstance()
{
	if (instance)
		delete instance;
}

Game::Game()
{
	ogreRoot = NULL;
	ogreRoot = new Ogre::Root();
	sceneManager = NULL;
	window = NULL;
	camera = NULL;
	viewport = NULL;
}

Game::~Game()
{
	destroyInput();

	if (viewport)
		delete viewport;

	if (camera)
		delete camera;

	if (sceneManager)
		delete sceneManager;

	if (window)
		delete window;

	if (ogreRoot)
		delete ogreRoot;
}

void Game::run()
{
	if (!ogreRoot)
		return;

	if (!ogreRoot->showConfigDialog())
		return;

	ogreRoot->initialise(true, "OgreWindow");

	createWindow();
	createSceneManager();
	createCamera();
	createViewport();
	createInput();
	setupResourceManager();

	Ogre::Entity *ogreHead = sceneManager->createEntity("OgreHead", "T80_obj.mesh");
	Ogre::SceneNode *ogreHeadNode = sceneManager->getRootSceneNode()
									->createChildSceneNode("Head Node", Ogre::Vector3(-50.0f, 30.0f, 0.0f));
	ogreHeadNode->attachObject(ogreHead);

	Ogre::Light *directionalLight = sceneManager->createLight("DirectionalLight");
	directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
	directionalLight->setDiffuseColour(Ogre::ColourValue(.4, 0, 0));
	directionalLight->setSpecularColour(Ogre::ColourValue(.4, 0, 0));
	directionalLight->setDirection(Ogre::Vector3(0, -1, 1));

	ogreRoot->addFrameListener(this);
	ogreRoot->startRendering();
}

void Game::createWindow()
{
	if (ogreRoot != NULL)
		window = ogreRoot->getAutoCreatedWindow();
}

void Game::createCamera()
{
	if (sceneManager != NULL)
	{
		camera = sceneManager->createCamera("MainCam");
		camera->setPosition(Ogre::Vector3(1000, 1000, 1000));
		camera->lookAt(Ogre::Vector3(0, 0, 0));
		camera->setNearClipDistance(5);
	}
}

void Game::createSceneManager()
{
	if (ogreRoot != NULL)
	{
		sceneManager = ogreRoot->createSceneManager(Ogre::ST_GENERIC, "MainSceneManager");
		sceneManager->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
		sceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	}
}

void Game::createViewport()
{
	if (window != NULL && camera != NULL)
	{
		viewport = window->addViewport(camera);
		viewport->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.0f));
		camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));
	}
}

void Game::setupResourceManager()
{
//	Ogre::String resourcesCfg;

//#ifdef _DEBUG
//	resourcesCfg = "resources_d.cfg";
//#else
//	resourcesCfg = "resources.cfg";
//#endif

//	Ogre::ConfigFile cf;
//	cf.load(resourcesCfg);

	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../media/", "FileSystem", "General");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../media/materials/scripts", "FileSystem", "General");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../media/materials/textures", "FileSystem", "General");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../media/models", "FileSystem", "General");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../media/packs", "FileSystem", "General");
	Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("General");
	Ogre::ResourceGroupManager::getSingleton().loadResourceGroup("General");


// 	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
// 
// 	Ogre::String secName, typeName, archName;
// 	while (seci.hasMoreElements())
// 	{
// 		secName = seci.peekNextKey();
// 		Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
// 		Ogre::ConfigFile::SettingsMultiMap::iterator i;
// 		for (i = settings->begin(); i != settings->end(); ++i)
// 		{
// 			typeName = i->first;
// 			archName = i->second;
// 			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
// 				archName, typeName, secName);
// 		}
// 	}
}

bool Game::frameStarted(const Ogre::FrameEvent &fe)
{
	if (window->isClosed())
		return false;
	captureInput();
	return true;
}

bool Game::frameEnded(const Ogre::FrameEvent &fe)
{
	return true;
}

void Game::captureInput()
{
	if (mouse != NULL)
		mouse->capture();
	if (keyboard != NULL)
		keyboard->capture();
}

void Game::destroyInput()
{
	if (mouse != NULL)
		inputManager->destroyInputObject(mouse);
	if (keyboard != NULL)
		inputManager->destroyInputObject(keyboard);
	OIS::InputManager::destroyInputSystem(inputManager);
	inputManager = NULL;
}

void Game::createInput()
{
	OIS::ParamList pl;
	size_t windowHnd = 0;
	std::ostringstream windowHndStr;
	
	window->getCustomAttribute("WINDOW", &windowHnd);
	windowHndStr << windowHnd;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
	
	inputManager = OIS::InputManager::createInputSystem(pl);
	
	keyboard = static_cast<OIS::Keyboard*>(inputManager->createInputObject(OIS::OISKeyboard, true));
	mouse = static_cast<OIS::Mouse*>(inputManager->createInputObject(OIS::OISMouse, true));
	
	unsigned int width, height, depth;
	int left, top;
	window->getMetrics(width, height, depth, left, top);
	mouse->getMouseState().width = width;
	mouse->getMouseState().height = height;
}

