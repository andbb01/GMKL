#include "../Types.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/TextObject/TextObject.h"
#ifndef GRAPH_CONTR

class GameObject;

class Graphics{
  private:

    /**
     * Finestra della libreria SDL
     */
    SDL_Window *win;
    /**
     * Render grafico della libreria SDL, necessario per aggiornare o modificare 
     * lo stato della finestra
     */
    SDL_Renderer *ren;
    /**
     * Dimensione della finestra
     */
    Point size;
    /**
     * Ritardo di aggiornamento della grafica
     */
    int delay;
  public:
    /**
     * Costruttore con ritardo di 40 ms (STD_DELAY)
     */
    Graphics();
    /**
     * Costruttore con delay personalizzato
     */
    Graphics(int delay);
    /**
     * Crea la finestra di larghezza w e altezza h
     */
    void createWindow(int w, int h);
    /**
     * Imposta il colore di background ad rgb
     */
    void setBackgroundColor(int r, int g, int b);
    /**
     * Aggiorna la grafica successivamente alla modifica
     */
    void update();
    /**
     * Imposta il colore per il disegno di figure elementari (punti, rettangoli, etc.)
     */
    void setDrawingColor(int r, int g, int b);
    /**
     * Pisegna un punto
     */
    void drawPoint(Point p);
    /**
     * Disegna un rettangolo vuoto
     */
    void drawRect(Rect r);
    /**
     * Disegna un oggetto di tipo GameObject (o sottoclassi)
     */
    void drawObject(GameObject obj);
    /**
     * Disegna un oggetto con texture nulla (o non) sotto forma di rettangolo di colore rgb 
     */
    void drawObject(GameObject obj, int r, int g, int b);
    /**
     * Disegna un TextObject considerando eventuale texture di sfondo e testo sopra scritto
     */
    void drawObject(TextObject obj);
    /**
     * Imposta la sprite (texture) di un oggetto in modo da renderne possibile la rappresentazione grafica
     */
    void setObjSprite(std::string fileName, GameObject *obj);
    /**
     * Imposta le texture di un oggetto con testo considerando sia sfondo che testo attualmente attivo
     * Cambiando il testo sarà necessario chiamare nuovamente questo metodo
     */
    void setObjSprite(TextObject *obj, unsigned char r, unsigned char g, unsigned char b);
    /**
     * Utilizzo consigliato solo se si comprende abbastanza bene la libreria SDL
     * restituisce il render della finestra per permettere di effettuare operazioni esternamente alla classe
     * Nota: alcuni metodi delle altre classi potrebbero evere il valore restituito come parametro in ingresso
     */
    SDL_Renderer *externUpdate();
    /**
     * Elimina tutte le impostazioni grafiche per "liberare spazio in memoria"
     */
    ~Graphics();
};

#endif

#define GRAPH_CONTR 1
