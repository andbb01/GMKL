#include "../GameObject.h"

#ifndef TEX_CONTR

/**
 * Classe per la gestione di oggetti grafici contenenti testo
 * eredita tutte le proprietà di Game object in modo da poter essere gestita analogamente
 */

class TextObject : public GameObject{
    private:
        std::string text;
        std::string fontName;
        SDL_Texture *font_tex;
    public:
        /**
         * In fase di creazione si possono decidere dimensioni del box testo iniziale e font
         */
        TextObject(int x, int y, int w, int h,  std::string text, std::string fontName) : GameObject(x, y, w, h){
            this->text = text;
            this->fontName = fontName;
        }
        /**
         * Se il font non è specificato viene inizializato a "fonts/arial.ttf" 
         * <strong>Attenzione:</strong>
         *  rendere sempre disponibile questo percorso per evitare malfunzionamenti
         */
        TextObject(int x, int y, int w, int h,  std::string text) : GameObject(x, y, w, h){
            this->text = text;
            fontName = "fonts/arial.ttf";
        }
        TextObject(int x, int y, int w, int h) : GameObject(x, y, w, h){
            this->text = "";
            this->fontName = "fonts/arial.ttf";
        }
        std::string getTxt();
        std::string getCurrentFont();
        void setFontTexture(SDL_Texture *t);
        SDL_Texture *getObjFontSprite();
};

#endif

#define TEX_CONTR 1