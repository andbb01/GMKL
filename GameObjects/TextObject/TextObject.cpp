#include "TextObject.h"

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