//Include-Depandancies(cleared later)
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <string>

//Internal-Depandancies(cleared later)
#include "foxy-mouse.h"
#include "foxy-ani.h"

class FObject {
private:
	std::string name;
	std::string type;
	int x,y,width,height,event;
	SDL_Window* wnd_ptr;
	SDL_Renderer* ren_ptr;
	FMouse* mouse;
	FAni ani;
	
public:
	FObject() {
		//Empty
	}
	~FObject() {
		//Empty
	}
	
	createObj(std::string id,std::string ty_pe,int x_pos,int y_pos,int w,int h,SDL_Window* w_ptr,SDL_Renderer* r_ptr,FMouse* m) {
		name=id;
		type=ty_pe;
		x=x_pos;
		y=y_pos;
		width=w;
		height=h;
		wnd_ptr=w_ptr;
		ren_ptr=r_ptr;
		mouse=m;
		event=0;
	}
	
	virtual void draw()=0;
	virtual void fadeIn() {
		//Overriden by Theme, but not important
	}
	virtual void fadeOut() {
		//Overriden by Theme, but not important
	}
	
	//Get & Set functions
	std::string getName() {return name;}
	std::string getType() {return type;}
	int getXPos() {return x;}
	int getYPos() {return y;}
	int getWidth() {return width;}
	int getHeight() {return height;}
	int getEvent() {return event;}
	FAni getAni() {return ani;}
	SDL_Window* getWindow() {return wnd_ptr;}
	SDL_Renderer* getRenderer() {return ren_ptr;}
	FMouse* getMouse() {return mouse;}
	void setXPos(int x_pos) {x=x_pos;}
	void setYPos(int y_pos) {y=y_pos;}
	void setWidth(int w) {width=w;}
	void setHeight(int h) {height=h;}
	void setAni(FAni a) {ani=a;}
	void setEvent(int e) {event=e;}
};
