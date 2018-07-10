#ifndef __FoxyTimer
#define __FoxyTimer

class FoxyTimer {
private:
  Uint32 ticks;
  Uint32 diff;
  bool running;
  bool paused;

public:
  FoxyTimer() {
    ticks=0;
    running=false;
    paused=false;
  }
  ~FoxyTimer() {
    //Empty
  }
  void start() {
    if(!running) {
      if(!paused) {
        ticks=SDL_GetTicks();
        running=true;
      } else {
        ticks=SDL_GetTicks()-diff;
        running=true;
        paused=false;
      }
    } else {
      ticks=SDL_GetTicks();
    }
  }
  void pause() {
    if(running&&!paused) {
      diff=SDL_GetTicks()-ticks;
      running=true;
      paused=true;
    }
  }
  void stop() {
    if(running) {
      ticks=0;
      running=false;
      paused=false;
    }
  }
  int getDiff() {return (int)(SDL_GetTicks()-ticks);}
};
#endif
