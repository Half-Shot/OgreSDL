#include "BareOgre.h"

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
  // Remove ourself as a window listener.
  Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
  windowClosed(mWindow);

  delete mRoot;
}

bool OgreSDL::go(void)
{
  fps = 60;
  fpsTime = float(1) / float(fps);
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
  // Set default mipmap level.
  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
  // Initialize all resource groups.
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

  // Create scene.
  createScene();

  // Initialize input. (OIS)
  initInput();

  // Set initial mouse clipping size.
  windowResized(mWindow);

  // Register as a Window listener.
  Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

  // Render loop.
  mRoot->addFrameListener(this);
  mWindow->setVisible(true);
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
  if (mWindow->isClosed()) return false;
  if (mShutdown) return false;

  return true;
}

bool OgreSDL::frameEnded(const Ogre::FrameEvent& evt)
{
    if(evt.timeSinceLastFrame > fpsTime){
        mRoot->renderOneFrame();
        SDL_GL_SwapWindow(sdlWindow);
    }
    return true;
}

// Adjust mouse clipping area.
void OgreSDL::windowResized(Ogre::RenderWindow* rw)
{
 return;
}
 
// Unattach OIS before window shutdown (very important under Linux).
void OgreSDL::windowClosed(Ogre::RenderWindow* rw)
{
  //Get rid of our SDL Stuff
  SDL_Quit();
  return;
}

//==============================================================================
// User Input (OIS)
//==============================================================================
bool OgreSDL::keyPressed( const OIS::KeyEvent& evt ) {
  mLog->logMessage("** Key Pressed **");

  switch (evt.key) {
    case OIS::KC_ESCAPE:
      mShutdown = true;
      break;

    case OIS::KC_SYSRQ:
      mWindow->writeContentsToTimestampedFile("screenshot_", ".jpg");
      break;

    case OIS::KC_F5:
      Ogre::TextureManager::getSingleton().reloadAll();
      break;

    case OIS::KC_UP:
    case OIS::KC_W:
      mDirection.z -= mMove;
      break;

    case OIS::KC_DOWN:
    case OIS::KC_S:
      mDirection.z += mMove;
      break;

    case OIS::KC_LEFT:
    case OIS::KC_A:
      mDirection.x -= mMove;
      break;

    case OIS::KC_RIGHT:
    case OIS::KC_D:
      mDirection.x += mMove;
      break;

    case OIS::KC_PGDOWN:
    case OIS::KC_E:
      mDirection.y -= mMove;
      break;

    case OIS::KC_PGUP:
    case OIS::KC_Q:
      mDirection.y += mMove;
      break;
    default:
      break;
  }
  return true;
}
bool OgreSDL::keyReleased( const OIS::KeyEvent& evt ){
  mLog->logMessage("** Key Released  **");

  switch (evt.key) {
    case OIS::KC_UP:
    case OIS::KC_W:
      mDirection.z += mMove;
      break;

    case OIS::KC_DOWN:
    case OIS::KC_S:
      mDirection.z -= mMove;
      break;

    case OIS::KC_LEFT:
    case OIS::KC_A:
      mDirection.x += mMove;
      break;

    case OIS::KC_RIGHT:
    case OIS::KC_D:
      mDirection.x -= mMove;
      break;

    case OIS::KC_PGDOWN:
    case OIS::KC_E:
      mDirection.y += mMove;
      break;

    case OIS::KC_PGUP:
    case OIS::KC_Q:
      mDirection.y -= mMove;
      break;

    default:
      break;
  }
  return true;

}
bool OgreSDL::mouseMoved( const OIS::MouseEvent& evt )
{
  //if (evt.state.buttonDown(OIS::MB_Right)) {
    mCamNode->yaw(Ogre::Degree(-mRotate * evt.state.X.rel),
                  Ogre::Node::TS_WORLD);
    mCamNode->pitch(Ogre::Degree(-mRotate * evt.state.Y.rel),
                    Ogre::Node::TS_LOCAL);
  //}
  return true;
}
bool OgreSDL::mousePressed( const OIS::MouseEvent& evt, OIS::MouseButtonID id )
{
  switch (id) {
    case OIS::MB_Left:
      break;
    default:
      break;
  }
  return true;
}
bool OgreSDL::mouseReleased( const OIS::MouseEvent& evt,OIS::MouseButtonID id )
{
  return true;
}
