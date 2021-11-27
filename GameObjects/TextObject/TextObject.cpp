#include "TextObject.h"
#include "../../GraphicsManager/Graphics.h"
#include "../../GameManager/MouseManager.h"
#include "../../GameManager/KeyboardManager.h"

std::string TextObject::getTxt(){
  return this->text;
}

std::string TextObject::getCurrentFont(){
  return this->fontName;
}

void TextObject::setFontTexture(SDL_Texture *t){
  this->font_tex = t;
}

SDL_Texture *TextObject::getObjFontSprite(){
  return this->font_tex;
}


void TextObject::setTxt(std::string txt){
  this->text = txt;
}

void TextObject::setTxtColor(unsigned char r, unsigned char g, unsigned char b){
  this->txtCol.r = r;
  this->txtCol.g = g;
  this->txtCol.b = b;
}

Color TextObject::getColor(){
  return this->txtCol;
}