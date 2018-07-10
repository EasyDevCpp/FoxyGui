#ifndef __FoxyMouse
#define __FoxyMouse

class FoxyMouse {
private:
	int m_x;
	int m_y;
	int m_state;
	FoxyTimer timer;

public:
	FoxyMouse() {
		timer.start();
	}
	~FoxyMouse() {
		//Empty
	}
	void update() {
		m_state=SDL_GetMouseState(&m_x,&m_y);
	}
	bool isHovering(int x,int y,int w,int h) {return m_x>=x&&m_x<=x+w&&m_y>=y&&m_y<=y+h;}
	int mouseState() {
		if(timer.getDiff()>=180) {
			timer.start();
			return (int)m_state;
		}
	}
	int getMouseX() {return m_x;}
	int getMouseY() {return m_y;}
};
#endif
