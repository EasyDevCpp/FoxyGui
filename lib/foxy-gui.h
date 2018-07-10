#ifndef __FoxyGui
#define __FoxyGui

/*
 * Information:
 * This class is used to implement the Mainframe on a class...
 * Main functions and capabilities are decleared here...
 *
 */

class FoxyGui {
private:
  SDL_Ptr<SDL_Window*> wnd_ptr;
  SDL_Ptr<SDL_Renderer*> ren_ptr;
  SDL_Ptr<FoxyContainer*> container;
  SDL_Event event;
  SDL_Ptr<WindowButtons*> wnd_btns;
  int wnd_type;

public:
  FoxyGui() {
    //Empty
  }
  ~FoxyGui() {
    SDL_Quit();
  }
  //Intresting: type defines the Window type...
  //            0 = Theme-Window, close;
  //            1 = Theme-Window, close + minimize + maximize
  //            2 = Theme-Window, fullscreen
  //            3 = Fullscreen-Mode
  //            4 = Normal-Window
  //            5 = Normal-Window, resizable
  void create(std::string title,int x,int y,int width,int height,int type=0) {
    SDL_Init(SDL_INIT_EVERYTHING);

    Uint32 flags;
    wnd_type=type;
    if(type==3) {
      flags=SDL_WINDOW_FULLSCREEN;
    } else if(type==4) {
      flags=SDL_WINDOW_SHOWN;
    } else if(type==5) {
      flags=SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE;
    } else {
      flags=SDL_WINDOW_BORDERLESS;
      if(type==2) {
        flags=flags|SDL_WINDOW_FULLSCREEN_DESKTOP;
      }
    }

    wnd_ptr=SDL_MakePtr<SDL_Window*>(SDL_CreateWindow(title.c_str(),x,y,width,height,flags));
    ren_ptr=SDL_MakePtr<SDL_Renderer*>(SDL_CreateRenderer(*wnd_ptr,-1,0));

    container=SDL_MakePtr<FoxyContainer*>(new FoxyContainer());
    (*container)->setWindow(wnd_ptr);
    (*container)->setRenderer(ren_ptr);

    wnd_btns=SDL_MakePtr<WindowButtons*>(new WindowButtons(container));
  }
  void close() {
    (*container)->setExit(true);
  }
  virtual void eventLoop() {}; //MUST BE OVERRIDDEN IN YOUR CODE!
  virtual void onExit() {
    //Ready for your turn...
    //Don't forget close() somewhere!!!
    close();
  }
  void show() {
    do {
      while(SDL_PollEvent(*SDL_MakePtr<SDL_Event*>(&event))) {
        if(event.type==SDL_QUIT) {
          onExit();
        }
      }
      SDL_RenderClear(*ren_ptr);
      (*wnd_btns)->draw();
      SDL_RenderPresent(*ren_ptr);
      SDL_Delay(10);
    } while(!(*container)->getExit());
  }
  std::string loadDesign(std::string path) {return "null";}
  void triggerEvent(int id,int timeout) {}
  //FoxyObject* getObject(std::string name) {}
};

#endif
