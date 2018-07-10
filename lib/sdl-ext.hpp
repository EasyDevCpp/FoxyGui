#ifndef __SDL_EXT
#define __SDL_EXT

void SDLExt_DrawRect(SDL_Ptr<SDL_Renderer*> r,int x,int y,int w,int h,SDL_Color c) {
  SDL_Rect temp={x,y,w,h};
  SDL_SetRenderDrawColor(*r,c.r,c.g,c.b,c.a);
  SDL_RenderDrawRect(*r,&temp);
}
void SDLExt_FillRect(SDL_Ptr<SDL_Renderer*> r,int x,int y,int w,int h,SDL_Color c) {
  SDL_Rect temp={x,y,w,h};
  SDL_SetRenderDrawColor(*r,c.r,c.g,c.b,c.a);
  SDL_RenderFillRect(*r,&temp);
}
void SDLExt_DrawTexture(SDL_Ptr<SDL_Renderer*> r,SDL_Ptr<SDL_Texture*> t,int x,int y,int w,int h) {
  SDL_Rect temp={x,y,w,h};
  SDL_RenderCopy(*r,*t,NULL,&temp);
}

#endif
