#include <SDL2/SDL.h>
#include <cmath>

#ifndef POINT_CONTR

/**
 * Classe per la gestione di un punto, molto basilare similare
 * al tipo vector.
*/
class Point{
  public:
    int x, y;
    /**
     * Costruttore della classe inizializza le coordinate (x, y).
     */
    Point(int x, int y);
    /**
     * Se non specificate le coordinate vengono inizializzate a (0, 0).
     */
    Point();
    /**
     * Necessario per l'utilizzo della libreria SDL2 alla base della gestione grafica di tutti gli oggetti 
     * converte la classa punto in una struct SDL_Point.
     */
    SDL_Point toSDL();
    /**
     * Restituisce la distanza tra il punto this e il punto other.
     */
    double distance(Point other);
    /**
     *  Operatore somma per due punti, somma le x e le y.
     */
    Point operator+(Point other);
    /**
     *  Operatore differenza tra due punti, sottrae x e y.
     */
    Point operator-(Point other);
    /**
     *  Operatore - su un punto, moltiplica per -1 entrambe le coordinate.
     */
    Point operator-();
    /**
     *  Operatore = per l'assegnamento di un punto ad una reference di quel punto
     *  necessario per l'assegnamento tramite operatore new.
     */
    Point* operator=(Point *other);
};


#endif

#define POINT_CONTR 1
