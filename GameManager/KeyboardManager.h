#include "../Types.h"

#ifndef KY_CNTR

/**
 * Classe di gestione degli input da tastiera permette di leggere numeri e lettere inserite dall'utente
 * (Per i valori di key si possono utilizzare le lettere e i numeri scritti come carattere o le shortcut di SDL)
 */
class KeyboardManager{
  public:
    /**
     * Restituisce lo stato del pulsante della tastiera, true se premuto, false altrimenti
     */
    static bool keyState(int key){
      if (key > '0' && key <= '9' ){
        key -= '1' - SDL_SCANCODE_1;
      } else if (key == '0'){
        key -= '0' - SDL_SCANCODE_0;
      } else if (key >= 'a' && key <= 'z'){
        key -= 'a' - SDL_SCANCODE_A;
      }

      const Uint8 *KeyState = SDL_GetKeyboardState(NULL);
    	if (KeyState[key])
    		return true;
    	else return false;
    }
};

#endif

#define KEY_CNTR 1