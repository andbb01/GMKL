#include "../Types.h"

#ifndef WIN_CNTR

/**
 * Classe per la gestione dei principali eventi che influenzano la finestra
 * (in fase iniziale)
 */
class WindowManager{
  private:
    static SDL_Event event;
  public:
    /**
     * Verifica se è stato premuto il tasto chiudi sulla finestra
     */
    static bool exitEvent(){
      if (event.type == SDL_QUIT)
        return true;
      return false;
    }

    /**
     * Verifica se un qualsiasi evento si è verificato (per i codici degli eventi vedere la documentazione SDL)
     */
    static bool actionState(int ev){
      if (ev == event.type)
        return true;
      return false;
    }
    /**
     * Funzione di aggiornamento degli eventi da finestra (chiamata automaticammente dal gameMain)
     */
    static void updateEvent(){
      SDL_PollEvent(&event);
    }
};

SDL_Event WindowManager::event;

#endif

#define WIN_CNTR 1