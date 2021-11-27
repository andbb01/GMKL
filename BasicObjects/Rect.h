#include <SDL2/SDL.h>
#include "Point.h"
#define V_NUM 4

class Point;

#ifndef REC_CONTR

/**
 * Classe rettangolo, consiste nel box fondamentale per la rappresentazione grafica e per il movimento degli GameObjects
 * ogni cosa viene schematizzata come rettangolo con all'interno una texture
 */
class Rect{
  public:
    /**
     * Vertice in alto a sinistra del rettangolo
     */
    Point v1;
    /**
     * Larghezza (width) del rettangolo
     */
    int w;
    /**
     * Altezza (height) del rettangolo
     */
    int h;
    /**
     * Inizializza tutte le dimensioni al valore inserito (x, y) sono il punto v1
     */
    Rect(int x, int y, int w, int h);
    /**
     * Inizializza tutte le grandezze a 0
     */
    Rect();
    /**
     * Restituisce un array di dimensione 4 di tutti i vertici del rettangolo
     */
    Point *vertexes();
    /**
     * Funzione necessaria per utilizzare tutte le funzioni di SDL, converte la classe rettangolo in una struct SDL_Rect
     */
    SDL_Rect toSDL();
    /**
     * Verifica se un punto p è contenuto nel rettangolo restituisce true se è così false altrimenti
     */
    bool contained(Point p);
};

#endif

#define REC_CONTR 1
