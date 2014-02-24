#ifndef __Program_h_
#define __Program_h_

#define SDL2_SOUND_ENABLED

#include "OgreSDL.h"
#include "ExampleGame.h"
#include <SDL2/SDL.h>
#include <signal.h>
#include <stdio.h>
class Program
{
 public:
  void siginthandler(int param);
  Program();
  virtual ~Program();
};

#endif
