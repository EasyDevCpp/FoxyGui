#ifndef __FoxyContainer
#define __FoxyContainer

/*
 * Information:
 * This class is used for internal functions only!
 * It's not intended to be used by anyone...
 *
 */

class FoxyContainer {
private:
  SDL_Ptr<SDL_Window*> wnd_ptr;
  SDL_Ptr<SDL_Renderer*> ren_ptr;
  SDL_Ptr<FoxyMouse*> mouse;
  int scene;
  bool popup;
  bool exit;

public:
  FoxyContainer() {
    scene=1;
    popup=false;
    exit=false;
  }
  ~FoxyContainer() {
    //Empty
  }
  //set-methods
  void setWindow(SDL_Ptr<SDL_Window*> w) {wnd_ptr=w;}
  void setRenderer(SDL_Ptr<SDL_Renderer*> r) {ren_ptr=r;}
  void setMouse(SDL_Ptr<FoxyMouse*> m) {mouse=m;}
  void setScene(int s) {if(s!=0) scene=s;}
  //Used to interrupt the event loop after a popup is created...
  //This function must be(or should be) called in the themes
  //fadeIn() overwrite... Just for popups!
  void setPopup(bool p) {popup=p;}
  void setExit(bool e) {exit=e;}
  //get-methods
  SDL_Ptr<SDL_Window*> getWindow() {return wnd_ptr;}
  SDL_Ptr<SDL_Renderer*> getRenderer() {return ren_ptr;}
  SDL_Ptr<FoxyMouse*> getMouse() {return mouse;}
  int getScene() {return scene;}
  bool getPopup() {return popup;}
  bool getExit() {return exit;}
};

#endif
