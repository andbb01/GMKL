#include "Graphics.h"
#include "../GameObjects/GameObject.h"

Graphics::Graphics(){
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
  TTF_Init();
  this->delay = STD_DELAY;
}

Graphics::Graphics(int delay){
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
  TTF_Init();
  this->delay = delay;
}

void Graphics::createWindow(int w, int h){
  this->size.x = w;
  this->size.y = h;
  SDL_CreateWindowAndRenderer(this->size.x, this->size.y, 0, &win, &ren);
}

void Graphics::setBackgroundColor(int r, int g, int b){
  SDL_RenderClear(ren);
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
    spr_info sprite;
    SDL_Rect tmp_pos, out_frm;
    tmp_pos = obj.getObjPosition().toSDL();
    sprite = obj.getSpriteInfo();
    if (obj.getObjSprite() != NULL){
      if (sprite.num_lin == 0)
        SDL_RenderCopyEx(ren, obj.getObjSprite(), NULL, &tmp_pos, obj.getObjAngle(), NULL, (SDL_RendererFlip)sprite.flip_state);
      else{
          out_frm.w = sprite.size.x;
          out_frm.h = sprite.size.y;
          out_frm.y = sprite.curr_lin * out_frm.h;
          out_frm.x = (sprite.frame_num % sprite.fxl) * out_frm.w;
          SDL_RenderCopyEx(ren, obj.getObjSprite(), &out_frm, &tmp_pos, obj.getObjAngle(), NULL, (SDL_RendererFlip)sprite.flip_state);
      }
    } else
      SDL_RenderFillRect(this->ren, &tmp_pos);
}

 void Graphics::drawObject(TextObject obj){
  this->drawObject((GameObject)obj);
  SDL_Rect tmp_pos;
  tmp_pos = obj.getTextBox().toSDL();
  SDL_RenderCopyEx(ren, obj.getObjFontSprite(), NULL, &tmp_pos, obj.getObjAngle(), NULL, SDL_FLIP_NONE);
}

void Graphics::drawPoint(Point p){
  SDL_RenderDrawPoint(this->ren, p.x, p.y);
}

void Graphics::drawRect(Rect r){
  SDL_Rect tmp;
  tmp = r.toSDL();
  SDL_RenderDrawRect(ren, &tmp);
}


void Graphics::setObjSprite(std::string fileName, GameObject *obj){
  SDL_Surface *sur;

  sur = IMG_Load(fileName.c_str());
  obj->setTexture(SDL_CreateTextureFromSurface(ren, sur));

  SDL_FreeSurface(sur);
}

void Graphics::setObjSprite(std::string fileName, TextObject *obj){
  SDL_Surface *sur;
  TTF_Font *font;
  SDL_Color c;
  c = obj->getColor();
  c.a = SDL_ALPHA_OPAQUE;

  font = TTF_OpenFont(obj->getCurrentFont().c_str(), 1000);

  sur = TTF_RenderText_Solid(font, obj->getTxt().c_str(), c);

  obj->setFontTexture(SDL_CreateTextureFromSurface(ren, sur));

  SDL_FreeSurface(sur);
  TTF_CloseFont(font);

  sur = IMG_Load(fileName.c_str());
  obj->setTexture(SDL_CreateTextureFromSurface(ren, sur));

  SDL_FreeSurface(sur);
}

void Graphics::setObjSprite(TextObject *obj){
  SDL_Surface *sur;
  TTF_Font *font;
  SDL_Color c;
  c = obj->getColor();
  c.a = SDL_ALPHA_OPAQUE;

  font = TTF_OpenFont(obj->getCurrentFont().c_str(), 1000);

  sur = TTF_RenderText_Solid(font, obj->getTxt().c_str(), c);

  obj->setFontTexture(SDL_CreateTextureFromSurface(ren, sur));

  SDL_FreeSurface(sur);
  TTF_CloseFont(font);
}

void Graphics::fulllScreen(bool state){
  SDL_SetWindowFullscreen(win, state);
}

Point Graphics::windowSize(){
  Point p;
  SDL_GetWindowSize(win, &p.x, &p.y);
  return p;
}

void Graphics::removeBorder(){
  SDL_SetWindowBordered(win, SDL_FALSE);
}