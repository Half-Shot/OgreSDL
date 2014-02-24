#ifndef __ExampleGame_h_
#define __ExampleGame_h_

#include "Program.h"
#include "OgreSDL.h"
#include <SDL2/SDL.h>
#ifdef SDL2_SOUND_ENABLED
#include <SDL2/SDL_mixer.h>
#endif
class ExampleGame : public OgreSDL
{
 public:
    ExampleGame(void);
    ~ExampleGame(void);
    bool go(void);
 protected:
    void createScene();
    void update(Ogre::FrameEvent frameEvent);
    void draw(const Ogre::FrameEvent &frameEvent);
    void handleInput(const SDL_Event &event);
    #ifdef SDL2_SOUND_ENABLED
    Mix_Music *backgroundTrack;
    #endif
    Ogre::Real mRotate;
    Ogre::Real mMove;
    Ogre::Vector3 mDirection;
    Ogre::Vector3 cameraVelocity;
    float camMod;

    Ogre::Radian rotAngle;
    Ogre::SceneNode* headNode;
    Ogre::Timer rotTimer;
};
#endif
