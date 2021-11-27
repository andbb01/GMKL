#include "../GameObject.h"

#ifndef TEX_CONTR

/**
 * Classe per la gestione di oggetti grafici contenenti testo
 * eredita tutte le proprietà di Game object in modo da poter essere gestita analogamente
 */

class TextObject : public GameObject{
    private:
        /**
         * Testo del box
         */
        std::string text;
        /**
         * Percorso del font utilizzato (relativo o assoluto)
         */
        std::string fontName;
        /**
         * Texture per la rappresentazione del testo, generata automaticamente dal metodo setObjSprite di Graphics
         */
        SDL_Texture *font_tex;
        /**
         * Struttura equivalente e SDL_Color per la gestione del colore del testo
         */
        Color txtCol;
        /**
         * Se l'oggetto viene usato come input box definisce se si è in fase di input o no
         */
        bool onObj = false;
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
        /**
         * Costruttore della classe con font di default "font/arial.ttf" e testo vuoto
         */
        TextObject(int x, int y, int w, int h) : GameObject(x, y, w, h){
            this->text = "";
            this->fontName = "fonts/arial.ttf";
        }
        /**
         * Restituisce il testo della della casella di testo
         */
        std::string getTxt();
        /**
         * Restituisce il percorso del font attualmente attivo nella classe
         */
        std::string getCurrentFont();
        /**
         * Imposta la texture per la scrittura del testo, solitamente chiamato indipendentemente dal metodo setObjSprite della classe Graphics
         */
        void setFontTexture(SDL_Texture *t);
        /**
         * Restituisce l'attuale texture dell'oggetto, solitamente chiamato automaticamente dal metodo drawObject della classe Graphics
         */
        SDL_Texture *getObjFontSprite();
        /**
         * Imposta il testo da mostrare nella sprite
         */
        void setTxt(std::string txt);
        /**
         * Imposta il colore del testo utilizzando il valore rgb
         */
        void setTxtColor(unsigned char r, unsigned char g, unsigned char b);
        /**
         * Restituisce il colore del testo attualmente attivo sotto forma di struct Color
         */
        Color getColor();
};

#endif

#define TEX_CONTR 1