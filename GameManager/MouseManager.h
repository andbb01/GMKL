#include "../Types.h"
#include "../GameObjects/GameObject.h"

#ifndef MOUS_CONTR

/**
 * Classe per la gestione degli input da mouse per i valori da utilizzare consultare le costanti
 */
class MouseManager{
    public:
        /**
         * Restituisce la posizione corrente del mouse sotto forma di calsse Point
         */
        static Point getPosition(){
            Point p;
            SDL_GetMouseState(&p.x, &p.y);
            return p;
        }
        /**
         * Restituisce lo stato dei vari tasti del mouse, true se premuto, false altrimenti
         */
        static bool buttonState(int but){
            if (but == SDL_GetMouseState(NULL, NULL))
                return true;
            return false;
        }
        /**
         * Controlla se il mouse è all'interno di un oggetto (obj)
         */
        static bool inObject(GameObject obj){
            Rect o;
            o = obj.getObjPosition();
            Point m = MouseManager::getPosition();
            if (o.contained(m))
                return true;
            return false;
        }
        /**
         * Metodo per la gestione dello scroll del mouse restituisce 1, 0 o -1 in funzione della direzione della rotazione della rondella
         */
        static int mouseWheel(){
            SDL_Event ev;
            SDL_PollEvent(&ev);
            if (ev.type == SDL_MOUSEWHEEL){
               return ev.wheel.y;
            }
            return 0;
        }
};

#endif

#define MOUS_CONTR 1