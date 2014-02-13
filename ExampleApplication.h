#ifndef __ExampleApplication_h_
#define __ExampleApplication_h_

#include "BareOgre.h"

class ExampleApplication : public OgreSDL
{
 public:
  ExampleApplication();
  virtual ~ExampleApplication();

 protected:
  virtual void createScene();
};

#endif // #ifndef __ExampleApplication_h_
