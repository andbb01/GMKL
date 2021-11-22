#include "Point.h"

Point::Point(int x, int y){
  this->x = x;
  this->y = y;
}

Point::Point(){
  this->x = 0;
  this->y = 0;
}

SDL_Point Point::toSDL(){
  SDL_Point p;
  p.x = this->x;
  p.y = this->y;

  return p;
}

double Point::distance(Point other){
  return sqrt((double) ((this->x - other.x) * (this->x - other.x) +  (this->y - other.y) * (this->y - other.y)));
}

Point Point::operator+(Point other){
  Point sum;
  sum.x = this->x + other.x;
  sum.y = this->y + other.y;
  return sum;
}

Point Point::operator-(Point other){
  Point diff;
  diff.x = this->x - other.x;
  diff.y = this->y - other.y;
  return diff;
}

Point Point::operator-(){
  Point neg;
  neg.x = -this->x;
  neg.y = -this->y;
  return neg;
}

Point* Point::operator=(Point *other){
  this->x = other->x;
  this->y = other->y;
  return this;
}
