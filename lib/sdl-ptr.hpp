#ifndef __SDL_PTR
#define __SDL_PTR

  // Forget about these SDL_Frees and these SDL_Destroys...
  // These days are over!
  //
  // Features:
  // + More RAM efficiency!
  // + Easy handling!
  // + Can be used for more than just SDL!
  // + Matches the newest C++-Standard!
  // + Less code, more fun!

  /*
	Example 1:
	SDL_Ptr<SDL_Window*> wnd=SDL_MakePtr<SDL_Window*>(...);

	Example 2:
	SDL_Event e;
	SDL_PollEvent(*SDL_MakePtr<SDL_Event*>(&e));

	Example 3:
	SDL_Ptr<SDL_Renderer*> ren;
	...
	SDL_RenderPresent(*ren);

  Example 4:
  SDL_Ptr<Class*> obj;
  ...
  //obj->method(); Won't work!
  (*obj)->method(); //Works!
  */

  #ifdef __cplusplus
    #include <iostream>
    #include <memory>
    #include <string>

    #ifndef SDL_h_
      #ifdef _WIN32
        #include <SDL.h>
      #else
        #include <SDL2/SDL.h>
      #endif
    #endif
  #endif

  template<typename T>
  using SDL_Ptr=std::shared_ptr<T>;

  template<typename T>
  std::shared_ptr<T> SDL_MakePtr(T a) {
    return std::make_shared<T>(a);
  }
#endif
