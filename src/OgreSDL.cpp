#include "OgreSDL.h"

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
  //Mix_CloseAudio();
  SDL_Quit();

  mRoot->getSingleton().queueEndRendering(false);
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
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  SDL_Window *sdlWindow = SDL_CreateWindow("OgreSDL",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        640,
                                        480,
                                        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
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

  // Render loop.
  mRoot->addFrameListener(this);
  mRoot->startRendering();
  return true;
}

void OgreSDL::createScene()
{

}

void OgreSDL::setupResources()
{
  Ogre::ConfigFile cf;
  cf.load(mResourcesCfg);

  //TODO: convert to C++11
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
  update((Ogre::FrameEvent)evt);
  return true;
}

bool OgreSDL::frameEnded(const Ogre::FrameEvent& evt)
{
    if (mShutdown) return false;
    if (evt.timeSinceLastFrame < fpsTime) return true;
    SDL_GL_SwapWindow(sdlWindow);

    //Give me the current FPS
    cout << "Current FPS: " << (1 / evt.timeSinceLastFrame) << endl;
    return true;
}

void OgreSDL::update(Ogre::FrameEvent frameEvent)
{
    mShutdown = true; //No updating, no program.
}
