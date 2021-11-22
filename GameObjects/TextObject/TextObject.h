#include "../GameObject.h"

#ifndef TEX_CONTR

class TextObject : public GameObject{
    private:
        string text;
    public:
        TextObject(int x, int y, int w, int h,  string text) : GameObject(x, y, w, h){
            this->text = text;
        }
        string getText(){
            return this->text;
        }
};

#endif

#define TEX_CONTR