#ifndef __OgreSDL_h_
#define __OgreSDL_h_

#include <SDL2/SDL.h>
#ifdef SDL2_SOUND_ENABLED
#include <SDL2/SDL_mixer.h>
#endif
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>
#include <OgreEntity.h>
#include <OgreCamera.h>
#include <OgreConfigFile.h>
#include <OgreEntity.h>
#include <OgreException.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreViewport.h>
#include <OgreWindowEventUtilities.h>

using namespace std;

class OgreSDL : public Ogre::FrameListener
{
 public:
  OgreSDL(void);
  virtual ~OgreSDL(void);
  virtual bool go(void);
 protected:
  virtual void createScene();
  virtual void setupResources();
  virtual void update(Ogre::FrameEvent frameEvent);
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
  virtual bool frameEnded(const Ogre::FrameEvent& evt);
  Ogre::String mPluginsCfg;
  Ogre::String mResourcesCfg;
  Ogre::Root* mRoot;
  Ogre::LogManager* mLog;
  Ogre::RenderWindow* mWindow;
  Ogre::SceneManager* mSceneMgr;
  Ogre::Viewport* mViewport;
  Ogre::Camera* mCamera;
  Ogre::SceneNode *mCamNode;

  //SDL
  SDL_Window* sdlWindow;
  SDL_GLContext* sdlGLcontext;
  int fps;
  float fpsTime;
  float eventTime;
  bool mShutdown;
};

#endif // #ifndef __OgreSDL_h_
