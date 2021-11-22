#include <SDL2/SDL.h>
#include "Point.h"
#define V_NUM 4

class Point;

#ifndef REC_CONTR

class Rect{
  public:
    Point v1;
    int w,h;
    Rect(int x, int y, int w, int h);
    Rect();
    Point *vertexes();
    SDL_Rect toSDL();
    bool contained(Point p);
};

#endif

#define REC_CONTR 1
