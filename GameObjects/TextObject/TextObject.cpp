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

void TextObject::setPadding(int padding){
  int text_len;
  this->textBox.v1.x = this->position.v1.x + padding;
  this->textBox.v1.y = this->position.v1.y + padding;
  this->textBox.h = font_size;
  text_len = text.length();
  this->textBox.w = font_size/2 * text_len;
}

Rect TextObject::getTextBox(){
  return textBox;
}