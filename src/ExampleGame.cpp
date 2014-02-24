#include "ExampleGame.h"

ExampleGame::ExampleGame()
{
}

ExampleGame::~ExampleGame()
{
}

bool ExampleGame::go()
{
    OgreSDL::go(); //Call this first, sets up SDL.
}

void ExampleGame::createScene()
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
    mViewport = mWindow->addViewport(mCamera);
    mViewport->setBackgroundColour(Ogre::ColourValue(0,0,0));

    // Set camera aspect ratio to match viewport.
    mCamera->setAspectRatio(Ogre::Real(mViewport->getActualWidth() / Ogre::Real(mViewport->getActualHeight())));

    // Add lighting.
    mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0,1.0,1.0));


    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);

    // Add meshes.
    Ogre::Entity *ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");
    headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    headNode->attachObject(ogreHead);

    //Set up cameraVelocity
    cameraVelocity = Ogre::Vector3::ZERO;
    camMod = 0.2;

    rotAngle = Ogre::Radian(0.0174532925);
    rotTimer = Ogre::Timer();
    #ifdef SDL2_SOUND_ENABLED
    if(Mix_Init(MIX_INIT_FLAC) == -1)
        cerr << "Mixer couldn't init, prepare for some bad crap!" << endl;
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
        cerr << "Mixer couldn't open audio, prepare for some bad crap!" << endl;
    Mix_AllocateChannels(0);
    backgroundTrack = Mix_LoadMUS("sampletrack.flac");
    #endif
}

void ExampleGame::update(Ogre::FrameEvent frameEvent)
{
    #ifdef SDL2_SOUND_ENABLED
    if(!Mix_PlayingMusic())
    {
        Mix_PlayMusic(backgroundTrack,1);
    }
    #endif
    if(rotTimer.getMilliseconds() >= (1000 / 20))
    {
        headNode->yaw(rotAngle);
        rotTimer.reset();
    }
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_KEYDOWN)
        {
            handleInput(e);
        }
        if(e.type == SDL_WINDOWEVENT)
        {
            if(e.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                mShutdown = true;
            }
            else if(e.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                mWindow->resize(e.window.data1,e.window.data2);
            }
        }
    }
}

void ExampleGame::handleInput(const SDL_Event &event)
{
    if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
    {
        mShutdown = true;
    }
}
