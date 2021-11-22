#include "Point.h"
#include "Rect.h"

Rect::Rect(int x, int y, int w, int h){
  Point p(x,y);
  this->v1 = p;
  this->w = w;
  this->h = h;
}

Rect::Rect(){
  Point tmp;
  this->v1 = tmp;
  this->w = 0;
  this->h = 0;
}

Point *Rect::vertexes(){
  Point *p;
  p = (Point*)malloc(sizeof(Point) * (V_NUM + 1));
  p[0] = new Point(v1.x, v1.y);
  p[1] = new Point(v1.x + w, v1.y);
  p[2] = new Point(v1.x, v1.y + h);
  p[3] = new Point(v1.x + w, v1.y + h);
  return p;
}

SDL_Rect Rect::toSDL(){
  SDL_Rect rect;
  rect.x = this->v1.x;
  rect.y = this->v1.y;
  rect.w = this->w;
  rect.h = this->h;
  return rect;
}

bool Rect::contained(Point p){
  if (p.x >= this->v1.x && p.x <= this->v1.x + this->w && p.y >= this->v1.y && p.y <= this->v1.y + this->h)
    return true;
  return false;
}
