//Include-Depandancies(cleared later)
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

//Internal-Depandancies(cleared later)
#include "foxy-main.h"
#include "foxy-scene.h"
#include "foxy-timer.h"
#include "foxy-mouse.h"

class FGui {
private:
	SDL_Window* wnd_ptr;
	SDL_Renderer* ren_ptr;
	SDL_Event event;
	std::vector<std::string> design_content;
	std::vector<std::string> on_event;
	std::vector<std::string> after_event;
	std::vector<FScene*> scenes;
	std::vector<bool> scene_whitelist;
	int active_scene;
	bool close;
	bool design_loaded;
	FMouse mouse;

public:
	FGui() {
		wnd_ptr=NULL;
		ren_ptr=NULL;
		active_scene=1; //0 reserved for always on-top elements
		close=false;
		design_loaded=false;
	}
	~FGui() {
		SDL_DestroyRenderer(ren_ptr);
		SDL_DestroyWindow(wnd_ptr);
	}

	//Initial functions
	void setWindowData(std::string title,int x,int y,int width,int height,int flags=0) {
		if(wnd_ptr==NULL) {
			wnd_ptr=SDL_CreateWindow(title.c_str(),x,y,width,height,SDL_WINDOW_BORDERLESS);
			ren_ptr=SDL_CreateRenderer(wnd_ptr,-1,0);
		} else {
			SDL_SetWindowTitle(wnd_ptr,title.c_str());
			SDL_SetWindowPosition(wnd_ptr,x,y);
			SDL_SetWindowSize(wnd_ptr,width,height);
		}
	}
	std::string loadDesignFile(std::string path) {
		std::string msg;
		bool error=false;
		std::ifstream file;

		if(!design_loaded) {
			file.open(path,std::ios_base::in);
			if(file.is_open()) {
				std::string temp;
				while(!file.eof()) {
					file>>temp;
					design_content.push_back(temp);
				}

				int scene_id=0;
				bool scene_sec=false;
				bool event_sec=false;

				for(auto t: design_content) {
					if(!scene_sec&&!event_sec) {
						if(t=="scene:") {
							scenes.push_back(new FScene(wnd_ptr,ren_ptr,&close));
							scene_sec=true;
							if(event_sec) { msg+="[WARNING] on-event section was not properly closed!\n";error=true;event_sec=false; }
						}
					} else {
						if(t==";") {
							if(scene_sec) scene_sec=false;
							if(event_sec) event_sec=false;
						}
						if(scene_sec) {
							if(t=="button") {

							} else if(t=="msgbox") {

							} else {
								msg+="[WARNING] Unknown object type!\n";
								error=true;
							}
						}
						if(event_sec) {

						}
					}
				}

				file.close();
			} else {
				msg+="[ERROR] File could not be found!\nFatal error... exit.\nSeg-Fault awaits you...";
				error=true;
			}
		} else {
			msg+="[WARNING] Only one design-file per session allowed!\nIgnored... exit.";
			error=true;
		}

		if(error) return msg;
		else return "[INFO] Initialization successful! No errors found.";
	}
};
