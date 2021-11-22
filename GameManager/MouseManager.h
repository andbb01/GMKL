#include <SDL2/SDL.h>
#include "../Types.h"
#include "../GameObjects/GameObject.h"
#ifndef MOUS_CONTR

class MouseManager{
    public:
        static Point getPosition(){
            Point p;
            SDL_GetMouseState(&p.x, &p.y);
            return p;
        }
        static bool buttonState(int but){
            if (but == SDL_GetMouseState(NULL, NULL))
                return true;
            return false;
        }
        static bool inObject(GameObject obj){
            Rect o;
            o = obj.getObjPosition();
            Point m = MouseManager::getPosition();
            if (o.contained(m))
                return true;
            return false;
        }
};

#endif

#define MOUS_CONTR 1