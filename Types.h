#include "BasicObjects/Point.h"
#include "BasicObjects/Rect.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <cstdlib>
#include <cmath>

/** @file
 * Include tutte gli header delle librerie esterne utilizzate da GMKL e le definizioni di alcune costanti 
 */

typedef SDL_Color Color;

#ifndef TYPES_CNTR

#define STD_DELAY   40
#define WIN_CLOSE   SDL_QUIT
#define KEY_ESC SDL_SCANCODE_ESCAPE
#define KEY_DELETE  SDLK_DELETE
#define KEY_ENTER   SDL_SCANCODE_RETURN
#define KEY_SPACE   SDL_SCANCODE_SPACE

#define MOUSE_RIGHT SDL_BUTTON_RMASK
#define MOUSE_LEFT  SDL_BUTTON_LMASK
#define MOUSE_MIDDLE SDL_BUTTON_MMASK
#define MOUSE_X2 SDL_BUTTON_X2MASK

#define DEF_NEAR_DIST 10

#endif

#define TYPES_CNTR 1