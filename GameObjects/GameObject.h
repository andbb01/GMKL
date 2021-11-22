#include "../Types.h"

#ifndef GAMOBJ_CONTR

class Graphics;

class GameObject{
protected:
    /**
     * Velocità dell'oggetto, può essere impostata per poi muovere
     * automaticamente l'oggetto della velocità prestabilita
     */
    Point vel;
    /**
     * Angolo di rotazione dell'oggetto, solo grafico il box di collisione resta fisso
     */
    double angle = 0;
    /**
     * Analogo a vel ma per la velocità di rotazione
     */
    double angle_vel;
    /**
     * Rettangolo positione, riporta le coordinate del vertice e le dimensioni del box, l'oggetto verrà disegnato in questo spazio
     * e ogni evento fisico sarà considerato su questo
     */
    Rect position;
    /**
     * Texture dell'oggetto, viene inizializzata con una sprite e rimane invariata per tutta la vita dell'oggetto
     * viene utilizzata dai metodi drawObject
     */
    SDL_Texture *tex;
  public:
    /**
     *  Costruttore senza classi particolari, position con (x, y, w, h) e tutto il resto a NULL
     */
    GameObject(int x, int y, int w, int h);
    /**
     *  Costruttore inizializza this->position e tutto il resto a NULL
     */
    GameObject(Rect position);
    SDL_Texture *getObjSprite();
    /**
     *  Restituisce un rettangolo (Rect) con tutte le informazioni sulla posizione e sulla dimensione 
     *  dell'oggetto
     */
    Rect getObjPosition();
    double getObjAngle();
    void objMove(int vx, int vy);
    void objMove();
    void objSetVelocity(int xvel, int yvel);
    void objTransport(int x, int y);
    void objRotate(double angle);
    void objRotate();
    void setTexture(SDL_Texture *t);
    void setObjSprite(const char *filename, SDL_Renderer *ren);
    void objSetAngVelocity(double w);
};

#endif

#define GAMOBJ_CONTR 1
