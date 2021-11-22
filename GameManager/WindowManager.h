#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Types.h"

#ifndef WIN_CNTR

class WindowManager{
  private:
    SDL_Event event;
  public:
    void updateEvents(){
      SDL_PollEvent(&event);
    }

    bool exitEvent(){
      if (event.type == SDL_QUIT)
        return true;
      return false;
    }


    bool actionState(int ev){
      if (ev == event.type)
        return true;
      return false;
    }

    void setEvent(int ev){
      event.type = ev;
    }
};

#endif

#define WIN_CNTR 1