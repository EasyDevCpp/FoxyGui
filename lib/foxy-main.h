//Include-Depandancies(cleared later)
#include <SDL2/SDL.h>

//Internal-Depandancies(cleared later)
#include "foxy-mouse.h"

class FMain {
private:
  SDL_Window* wnd_ptr;
	SDL_Renderer* ren_ptr;
	SDL_Event event;
  int active_scene;
	bool close;
  FMouse mouse;

public:
  FMain() {
    wnd_ptr=NULL;
    ren_ptr=NULL;
    active_scene=1;
    close=false;
  }
  ~FMain() {
    if(ren_ptr!=NULL) SDL_DestroyRenderer(ren_ptr);
    if(wnd_ptr!=NULL) SDL_DestroyWindow(wnd_ptr);
  }

  SDL_Window* getWindow() {return wnd_ptr;}
  SDL_Renderer* getRenderer() {return ren_ptr;}
  SDL_Event getEvent() {return event;}
  int getActiveScene() {return active_scene;}
  bool getClose() {return close;}
  FMouse getMouse() {return mouse;}

  void setActiveScene(int s) {active_scene=s;}
  void setClose(bool c) {close=c;}
  void setWindow(SDL_Window* wnd) {wnd_ptr=wnd;}
  void setRenderer(SDL_Renderer* ren) {ren_ptr=ren;}
};
