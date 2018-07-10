#include "../lib/foxy.h"
//#include "../lib/themes/default/default.h" //The Theme you want to be used
//#include "../lib/foxy-gui.h"

class App: public FoxyGui {
public:
	App() {
		create("Example",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,500,500);
		loadDesign("target.design");
		show();
	}
	void eventLoop() {
		std::cout << "test" << std::endl;
	}
};

int main() {
	App app;
	return 0;
}
