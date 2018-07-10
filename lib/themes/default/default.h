#ifndef __DEFAULT_THEME
#define __DEFAULT_THEME

namespace default_res {

}

/*
 * Window Controls
 */

void CloseButton::fadeIn() {

}
void CloseButton::fadeOut() {

}
void CloseButton::draw() {
  SDLExt_DrawRect((*getContainer())->getRenderer(),getX(),getY(),getWidth(),getHeight(),{255,0,0});
}

void MaximizeButton::fadeIn() {

}
void MaximizeButton::fadeOut() {

}
void MaximizeButton::draw() {

}

void MinimizeButton::fadeIn() {

}
void MinimizeButton::fadeOut() {

}
void MinimizeButton::draw() {

}

void WindowButtons::fadeIn() {

}
void WindowButtons::fadeOut() {

}
void WindowButtons::draw() {
  (*close_btn)->draw();
}

#endif
