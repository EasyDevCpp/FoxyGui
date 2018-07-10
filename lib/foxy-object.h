#ifndef __FoxyObject
#define __FoxyObject

class FoxyObject {
private:
  SDL_Ptr<FoxyContainer*> container;
  std::string name;
  int x;
  int y;
  int width;
  int height;
  bool is_popup;

public:
  FoxyObject() {
    //Empty
  }
  ~FoxyObject() {
    //Empty
  }
  void create(std::string name,int x,int y,int w,int h,bool is_popup,SDL_Ptr<FoxyContainer*> container) {
    this->container=container;
    this->name=name;
    this->x=x;
    this->y=y;
    this->width=w;
    this->height=h;
    this->is_popup=is_popup;
  }
  virtual void draw() {}
  virtual void fadeIn() {}
  virtual void fadeOut() {}
  int getEvent() {
    if(((*container)->getPopup()&&is_popup)||(!(*container)->getPopup()&&!is_popup))
      if((*(*container)->getMouse())->isHovering(x,y,width,height)) return (*(*container)->getMouse())->mouseState()+1;
    return 0;
  }
  //set-methods
  void setX(int x) {this->x=x;}
  void setY(int y) {this->x=y;}
  void setWidth(int w) {this->width=w;}
  void setHeight(int h) {this->height=h;}
  //get-methods
  int getX() {return x;}
  int getY() {return y;}
  int getWidth() {return width;}
  int getHeight() {return height;}
  std::string getName() {return name;}
  SDL_Ptr<FoxyContainer*> getContainer() {return container;}
};

#endif
