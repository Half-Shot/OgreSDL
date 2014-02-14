#ifndef __OgreSDL_h_
#define __OgreSDL_h_

#include <SDL2/SDL.h>
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

using namespace std;

class OgreSDL : public Ogre::FrameListener
{
 public:
  OgreSDL(void);
  virtual ~OgreSDL(void);
  virtual bool go(void);
 protected:
  virtual void createScene();
  virtual void initInput();
  virtual void setupResources();

  virtual bool doSDLEvents(const SDL_Event& event);
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
  virtual bool frameEnded(const Ogre::FrameEvent& evt);

  // private:
  Ogre::String mPluginsCfg;
  Ogre::String mResourcesCfg;
  Ogre::Root* mRoot;
  Ogre::LogManager* mLog;
  Ogre::RenderWindow* mWindow;
  Ogre::SceneManager* mSceneMgr;

  //SDL
  SDL_Window* sdlWindow;
  SDL_GLContext* sdlGLcontext;
  int fps;
  float fpsTime;
  float eventTime;
  bool mShutdown;

  Ogre::Camera* mCamera;
  Ogre::SceneNode *mCamNode;
  Ogre::Real mRotate;
  Ogre::Real mMove;
  Ogre::Vector3 mDirection;

  OIS::InputManager* mInputManager;
  OIS::Mouse* mMouse;
  OIS::Keyboard* mKeyboard;  
};

#endif // #ifndef __OgreSDL_h_
