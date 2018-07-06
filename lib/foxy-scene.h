//Include-Depandancies(cleared later)
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

//Internal-Depandancies(cleared later)
#include "foxy-object.h"
#include "foxy-mouse.h"

class FScene {
private:
	SDL_Window* wnd_ptr;
	SDL_Renderer* ren_ptr;
	bool* close_ptr;
	FMouse* mouse;
	std::vector<FObject*> objects;

public:
	FScene() {
		//Empty
	}
	FScene(SDL_Window* w_ptr,SDL_Renderer* r_ptr,bool* c_ptr) {
		wnd_ptr=w_ptr;
		ren_ptr=r_ptr;
		close_ptr=c_ptr;
	}
	~FScene() {
		//Empty
	}
	void addObj(FObject* obj) {
		if(obj!=nullptr) objects.push_back(obj);
	}
	FObject* getObj(int id) {
		if(id<objects.size()) return objects.at(id);
		else return nullptr;
	}
	std::vector<FObject*> getObjs() {
		return objects;
	}
};
