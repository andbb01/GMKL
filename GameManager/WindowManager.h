#include "../Types.h"

#ifndef WIN_CNTR

/**
 * Classe per la gestione dei principali eventi che influenzano la finestra
 * (in fase iniziale)
 */
class WindowManager{
  public:
    /**
     * Verifica se è stato premuto il tasto chiudi sulla finestra
     */
    static bool exitEvent(){
      SDL_Event event;
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
        return true;
      return false;
    }

    /**
     * Verifica se un qualsiasi evento si è verificato (per i codici degli eventi vedere la documentazione SDL)
     */
    static bool actionState(int ev){
      SDL_Event event;
      SDL_PollEvent(&event);
      if (ev == event.type)
        return true;
      return false;
    }
};

#endif

#define WIN_CNTR 1