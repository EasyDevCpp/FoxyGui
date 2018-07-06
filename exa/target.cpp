#include "../lib/foxy-main.h"
#include "../lib/themes/default/default.h" //The Theme you want to be used
#include "../lib/foxy-gui.h"

class App: public FGui {
	App() {
		setWindowData("Example",SDL_WINDOWPOS_DEFAULT,SDL_WINDOWPOS_DEFAULT,500,500);
		loadDesignFile("target.design");
	}
	void loop() {
		if(getObj("buttonMsg")->getEvent()==1) {
			triggerEvent(0,60);
		}
	}
};

int main() {
	App app;
	app.show();
	return 0;
}
