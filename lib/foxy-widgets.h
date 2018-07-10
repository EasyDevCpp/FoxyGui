#ifndef __FoxyWidgets
#define __FoxyWidgets

/*
 * Window Controls
 */

class CloseButton: public FoxyObject {
public:
  CloseButton() {
    //Empty
  }
  CloseButton(int x,int y,int w,int h,SDL_Ptr<FoxyContainer*> container) {
    create("window-close",x,y,w,h,false,container);
  }
  ~CloseButton() {
    //Empty
  }
  void fadeIn();
  void fadeOut();
  void draw();
};

class MaximizeButton: public FoxyObject {
private:
  bool maximized=false;
public:
  MaximizeButton() {
    //Empty
  }
  MaximizeButton(int x,int y,int w,int h,SDL_Ptr<FoxyContainer*> container) {
    create("window-max",x,y,w,h,false,container);
  }
  ~MaximizeButton() {
    //Empty
  }
  void setMaximized(bool m) {maximized=m;}
  bool getMaximized() {return maximized;}
  void fadeIn();
  void fadeOut();
  void draw();
};

class MinimizeButton: public FoxyObject {
public:
  MinimizeButton() {
    //Empty
  }
  MinimizeButton(int x,int y,int w,int h,SDL_Ptr<FoxyContainer*> container) {
    create("window-min",x,y,w,h,false,container);
  }
  ~MinimizeButton() {
    //Empty
  }
  void fadeIn();
  void fadeOut();
  void draw();
};

class WindowButtons: public FoxyObject {
private:
  SDL_Ptr<CloseButton*> close_btn;
  SDL_Ptr<MaximizeButton*> max_btn;
  SDL_Ptr<MinimizeButton*> min_btn;

public:
  WindowButtons() {
    //Empty
  }
  WindowButtons(SDL_Ptr<FoxyContainer*> container) {
    int x,w;
    SDL_GetWindowSize(*(*container)->getWindow(),&w,NULL);
    x=w-96;
    create("window-buttons",x,0,96,32,false,container);
    close_btn=SDL_MakePtr<CloseButton*>(new CloseButton(x+64,0,32,32,container));
    max_btn=SDL_MakePtr<MaximizeButton*>(new MaximizeButton(x+32,0,32,32,container));
    min_btn=SDL_MakePtr<MinimizeButton*>(new MinimizeButton(x,0,32,32,container));
  }
  ~WindowButtons() {
    //Empty
  }
  SDL_Ptr<CloseButton*> getCloseButton() {return close_btn;}
  SDL_Ptr<MaximizeButton*> getMaximizeButton() {return max_btn;}
  SDL_Ptr<MinimizeButton*> getMinimizeButton() {return min_btn;}
  void fadeIn();
  void fadeOut();
  void draw();
};

#endif
