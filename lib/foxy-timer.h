//Include-Depandancies(cleared later)
#include <SDL2/SDL.h>

class FTimer {
private:
  Uint32 ticks;
  Uint32 diff;
  bool running;
  bool pause;

public:
  FTimer() {
    ticks=0;
    running=false;
    pause=false;
  }
  ~FTimer() {
    //Empty
  }
  void start() {
    if(!running) {
      if(!pause) {
        ticks=SDL_GetTicks();
        running=true;
      } else {
        ticks=SDL_GetTicks()-diff;
        running=true;
        pause=false;
      }
    } else {
      ticks=SDL_GetTicks();
    }
  }
  void pause() {
    if(running&&!pause) {
      diff=SDL_GetTicks()-ticks;
      running=true;
      pause=true;
    }
  }
  void stop() {
    if(running) {
      ticks=0;
      running=false;
      pause=false;
    }
  }
  int getDiff() {return (int)(SDL_GetTicks()-ticks);}

};
