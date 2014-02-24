#include "Program.h"

Program::Program()
{
}

Program::~Program()
{
}

//-------------------------------------------------------------------------------------
//==============================================================================
// Cross-platform boilerplate main()
//==============================================================================
#if WINDOWS
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void siginthandler(int param)
{
    cout << "SIGINT requested application quit." << endl;
    exit(1);
}

#if WINDOWS
  INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[]) 
#endif
  {
    signal(SIGINT, siginthandler);
    try {
        ExampleGame game = ExampleGame();
        game.go();
    } catch( Ogre::Exception& e ) {
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"An exception has occured!", e.getFullDescription().c_str(),NULL);
      std::cerr << "An exception has occured: " << e.getFullDescription().c_str() << std::endl;
    }
    return 0;
  }

#ifdef __cplusplus
}
#endif


