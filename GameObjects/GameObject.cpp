#include "GameObject.h"
#include "../GraphicsManager/Graphics.h"

GameObject::GameObject(int x, int y, int w, int h){
  Rect tmp(x,y,w,h);
  this->position = tmp;
  this->tex = NULL;
}

GameObject::GameObject(Rect position){
  this->position = position;
  this->tex = NULL;
}

SDL_Texture *GameObject::getObjSprite(){
  return this->tex;
}

Rect GameObject::getObjPosition(){
  return position;
}

void GameObject::setTexture(SDL_Texture *t){
  this->tex = t;
}

void GameObject::setObjSprite(std::string filename, SDL_Renderer *ren){
  SDL_Surface *sur;
  sur = IMG_Load(filename.c_str());
  this->tex = SDL_CreateTextureFromSurface(ren, sur);

  free(sur);
}

void GameObject::objMove(int vx, int vy){
  this->position.v1.x += vx;
  this->position.v1.y += vy;
}

void GameObject::objMove(){
  this->position.v1.x += vel.x;
  this->position.v1.y += vel.y;
}

void GameObject::objSetVelocity(int xvel, int yvel){
  this->vel.x = xvel;
  this->vel.y = yvel;
}

void GameObject::objTransport(int x, int y){
  this->position.v1.x = x;
  this->position.v1.y = y;
}

void GameObject::objRotate(double angle){
  this->angle += angle;
}

void GameObject::objRotate(){
  this->angle += angle_vel;
}

void GameObject::objSetAngVelocity(double w){
  this->angle_vel = w;
}

double GameObject::getObjAngle(){
  return this->angle;
}
