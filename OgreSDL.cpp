#include "OgreSDL.h"

#include <OgreCamera.h>
#include <OgreConfigFile.h>
#include <OgreEntity.h>
#include <OgreException.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreViewport.h>
#include <OgreWindowEventUtilities.h>

//Custom Includes


OgreSDL::OgreSDL(void)
  : mRoot(0),
    mResourcesCfg(Ogre::StringUtil::BLANK),
    mPluginsCfg(Ogre::StringUtil::BLANK),
    mShutdown(false)
{
}

OgreSDL::~OgreSDL(void)
{
  //Remove SDL Stuff
  mRoot->getSingleton().queueEndRendering(false);
  SDL_Quit();
  delete mRoot;
}

bool OgreSDL::go(void)
{
  fps = 60;
  fpsTime = float(1) / float(fps);
  eventTime = 0.001f; //1000 events a second.
  mLog = new Ogre::LogManager;
  mLog->createLog("Ogre.log");

#ifdef _DEBUG
  mResourcesCfg = "resources_d.cfg";
  mPluginsCfg = "plugins_d.cfg";
#else
  mResourcesCfg = "resources.cfg";
  mPluginsCfg = "plugins.cfg";
#endif
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *sdlWindow = SDL_CreateWindow("OgreSDL",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        640,
                                        480,
                                        SDL_WINDOW_OPENGL);
  SDL_GLContext sdlGLcontext = SDL_GL_CreateContext(sdlWindow);

  mRoot = new Ogre::Root(mPluginsCfg);
  // Load resource paths from resources config file.
  setupResources();

  // Configure dialog.
  if (!mRoot->restoreConfig()) {
    return false;
  }

   mRoot->initialise(false); //Creating our own window.
   Ogre::NameValuePairList misc;
   #ifdef WINDOWS
        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        SDL_GetWMInfo(&wmInfo);

        size_t winHandle = reinterpret_cast<size_t>(wmInfo.window);
        size_t winGlContext = reinterpret_cast<size_t>(wmInfo.hglrc);

        misc["externalWindowHandle"] = StringConverter::toString(winHandle);
        misc["externalGLContext"] = StringConverter::toString(winGlContext);
    #else
        misc["currentGLContext"] = "True";
    #endif

  mWindow = mRoot->createRenderWindow("MainRenderWindow", 640, 480, false, &misc);
  mWindow->setVisible(true);

  // Set default mipmap level.
  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
  // Initialize all resource groups.
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

  // Create scene.
  createScene();

  // Initialize input. (OIS)
  initInput();

  // Render loop.
  mRoot->addFrameListener(this);
  mRoot->startRendering();
  return true;
}

void OgreSDL::createScene()
{
  // Create SceneManager.
  mSceneMgr = mRoot->createSceneManager("DefaultSceneManager");

  // Create a camera.
  mCamera = mSceneMgr->createCamera("PlayerCam");
  mCamera->setPosition(Ogre::Vector3(0,0,80));
  mCamera->lookAt(Ogre::Vector3(0,0,-3));
  mCamera->setNearClipDistance(5);
  mCamNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("CamNode");
  mCamNode->attachObject(mCamera);

  // Create one viewport, entire window.
  Ogre::Viewport* vp = mWindow->addViewport(mCamera);
  vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

  // Set camera aspect ratio to match viewport.
  mCamera->setAspectRatio(
    Ogre::Real(vp->getActualWidth() / Ogre::Real(vp->getActualHeight())));

  // Add lighting.
  //mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5,0.5,0.5));
  mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0,1.0,1.0));


  Ogre::Light* l = mSceneMgr->createLight("MainLight");
  l->setPosition(20,80,50);

  // Add meshes.
  Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");
  Ogre::SceneNode* headNode =
    mSceneMgr->getRootSceneNode()->createChildSceneNode();
  headNode->attachObject(ogreHead);

  // Set player control parameters.
  mRotate = 0.13;
  mMove = 250;
  mDirection = Ogre::Vector3::ZERO;
}

void OgreSDL::initInput()
{
 return;
}

void OgreSDL::setupResources()
{
  Ogre::ConfigFile cf;
  cf.load(mResourcesCfg);

  //TODO convert to C++11
  Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
  Ogre::String secName, typeName, archName;
  while (seci.hasMoreElements()) {
    secName = seci.peekNextKey();
    Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
    Ogre::ConfigFile::SettingsMultiMap::iterator i;
    for (i = settings->begin(); i != settings->end(); i++) {
      typeName = i->first;
      archName = i->second;
      Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
        archName, typeName, secName
      );
    }
  }
}

bool OgreSDL::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
  if (mShutdown) return false;
  //if (evt.timeSinceLastEvent < fpsTime) return true;
  SDL_Event e;

  //Get all queued events and process them.
  while (SDL_PollEvent(&e)){
    doSDLEvents(e);
  }

  return true;
}

bool OgreSDL::doSDLEvents(const SDL_Event& event)
{
    switch(event.type)
    {
        case SDL_WINDOWEVENT:
            if(event.window.event == SDL_WINDOWEVENT_CLOSE){
                cout << "Caught shutdown event" << endl;
                mShutdown = true;
            }
            break;
        case SDL_KEYDOWN:
            cout << "Key Down" << endl;
                switch(event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_A:
                        mCamera->moveRelative(Ogre::Vector3(0.5,0,0));
                        break;
                    case SDL_SCANCODE_D:
                        mCamera->moveRelative(Ogre::Vector3(-0.5,0,0));
                        break;
                    case SDL_SCANCODE_S:
                        mCamera->moveRelative(Ogre::Vector3(0,-0.5,0));
                        break;
                    case SDL_SCANCODE_W:
                        mCamera->moveRelative(Ogre::Vector3(0,0.5,0));
                        break;
               }
            break;
        case SDL_KEYUP:
            cout << "Key Down" << endl;
            break;
        default:
            cout << "Got a unknown event of " << event.type << endl;
            break;

    }
}

bool OgreSDL::frameEnded(const Ogre::FrameEvent& evt)
{
    if (evt.timeSinceLastEvent < fpsTime) return true;
    SDL_GL_SwapWindow(sdlWindow);
    return true;
}
