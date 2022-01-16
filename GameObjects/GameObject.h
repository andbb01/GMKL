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
    /**
     * Se si utilizza una sequenza di sprite da informazioni su questa
     */
     spr_info frame;
  public:
    /**
     *  Costruttore imposta position a (x, y, w, h) e tutto il resto a NULL
     */
    GameObject(int x, int y, int w, int h);
    /**
     *  Costruttore di default tutto a 0 o NULL
     */
    GameObject();
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
    /**
     * Restituisce l'angolo di rotazione dell'oggetto, angolo solo grafico, collisioni e tutto il resto vengono comunque calcolate rispetto al rettangolo non ruotato
     */
    double getObjAngle();
    /**
     * Mouve l'oggetto di vx sull'asse x e di vy sull'asse y
     */
    void objMove(int vx, int vy);
    /**
     * Mouve l'oggetto dei valori di val in quell'istante
     */
    void objMove();
    /**
     * Setta di valori di vel a (xvel, yvel)
     */
    void objSetVelocity(int xvel, int yvel);
    /**
     * Imposta la posizione dell'oggetto al punto (x, y)
     */
    void setObjPosition(int x, int y);
    /**
     * Imposta la posizione dell'oggetto al punto p
     */
    void setObjPosition(Point p);
    /**
     * Ruota l'oggetto del valore di angle
     */
    void objRotate(double angle);
    /**
     * Ruota l'oggetto del valore di angle_vel
     */
    void objRotate();
    /**
     * Imposta angle_vel al valore di w
     */
    void objSetAngVelocity(double w);
    /**
     * Imposta la texture dell'oggetto, solitamento chiamato indipendentemente dal metodo setObjSprite della classe Graphics
     */
    void setTexture(SDL_Texture *t);
    /**
     * Imposta la sprite dell'oggetto internamente ad esso (sconsigliato), per il parametro ren solitamente usato il metodo externUpdate della classe Graphics
     */
    void setObjSprite(std::string filename, SDL_Renderer *ren);
    /**
     * Imposta la dimensione dell'oggetto
     */
    void setObjSize(int w, int h);
    /**
     * Restituisce il vettore velocità (Point) dell'oggetto
     */
    Point getObjVelocity();
    /**
     * Inizializza un oggetto per renderlo animabile tramite gestione di frame
     */
    void beAnimable(int w, int h, int fxl);
    /**
     * Imposta il frame dell'animazione attuale a i
     */
    void setFrame(int i);
    /**
     * Imposta il flipping della texture dell'oggetto (comodo per rirpsrziare animazioni)
     */
    void setFlipping(int i);
    /**
     * Restituisce il campo spr_info
     */
    spr_info getSpriteInfo();
    /**
     * Imposta riga dell'animazione attuale
     */
    void setFrameLine(int i);
};

#endif

#define GAMOBJ_CONTR 1
