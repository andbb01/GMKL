#include "Graphics.h"
#include "../GameObjects/GameObject.h"

Graphics::Graphics(){
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
  this->delay = STD_DELAY;
}

Graphics::Graphics(int delay){
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
  this->delay = delay;
}

void Graphics::createWindow(int w, int h){
  this->size.x = w;
  this->size.y = h;
  SDL_CreateWindowAndRenderer(this->size.x, this->size.y, 0, &win, &ren);
}

void Graphics::setBackgroundColor(int r, int g, int b){
  this->setDrawingColor(r,g,b);
  SDL_RenderClear(ren);
}

void Graphics::setDrawingColor(int r, int g, int b){
  SDL_SetRenderDrawColor(ren, r, g, b, SDL_ALPHA_OPAQUE);
}

void Graphics::update(){
  SDL_RenderPresent(ren);
  SDL_Delay(delay);
}

SDL_Renderer *Graphics::externUpdate(){
  return ren;
}

void Graphics::drawObject(GameObject obj){
    SDL_Rect tmp_pos;
    tmp_pos = obj.getObjPosition().toSDL();
    SDL_RenderCopyEx(ren, obj.getObjSprite(), NULL, &tmp_pos, obj.getObjAngle(), NULL, SDL_FLIP_NONE);
}

void Graphics::drawObject(GameObject obj, int r, int g, int b){
  this->setDrawingColor(r, g, b);
  SDL_Rect tmp = obj.getObjPosition().toSDL();
  SDL_RenderFillRect(this->ren, &tmp);
}

void Graphics::drawPoint(Point p){
  SDL_RenderDrawPoint(this->ren, p.x, p.y);
}

void Graphics::drawRect(Rect r){
  SDL_Rect tmp;
  tmp = r.toSDL();
  SDL_RenderDrawRect(ren, &tmp);
}


void Graphics::setObjSprite(const char *fileName, GameObject *obj){
  SDL_Surface *sur;
  sur = IMG_Load(fileName);
  obj->setTexture(SDL_CreateTextureFromSurface(ren, sur));

  free(sur);
}

Graphics::~Graphics(){
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(ren);
  SDL_Quit();
}
