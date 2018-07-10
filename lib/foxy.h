#ifndef __Foxy
#define __Foxy

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

#ifdef WIN32
  #include <SDL.h>
  #include <SDL_ttf.h>
  #include <SDL_image.h>
#else
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_ttf.h>
  #include <SDL2/SDL_image.h>
#endif

#include "sdl-ptr.hpp"
#include "sdl-ext.hpp"

#include "foxy-timer.h"
#include "foxy-mouse.h"
#include "foxy-container.h"
#include "foxy-object.h"

#include "foxy-widgets.h"

#endif
