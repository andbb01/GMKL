#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Types.h"

#ifndef KY_CNTR

class KeyboardManager{
  public:
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