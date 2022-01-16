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
     * Imposta il colore di background ad rgb e "pulisce" la finestra
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
     * Disegna un oggetto di tipo GameObject (o sottoclassi) (per oggetti animabili stampa solo srpites sulla prima linea)
     */
    void drawObject(GameObject obj);
    /**
     * Disegna un TextObject considerando eventuale texture di sfondo e testo sopra scritto
     */
    void drawObject(TextObject obj);
    /**
     * Imposta la sprite (texture) di un oggetto in modo da renderne possibile la rappresentazione grafica
     */
    void setObjSprite(std::string fileName, GameObject *obj);
    /**
     * Imposta la texture grafica di un oggetto di testo, permette di disegnare sia il testo che lo sfondo (filename)
     */
    void setObjSprite(std::string fileName, TextObject *obj);
    /**
     * Imposta la texture grafica di un oggetto di testo senza aggiornare la texture di sfondo
     */
    void setObjSprite(TextObject *obj);
    /**
     * Utilizzo consigliato solo se si comprende abbastanza bene la libreria SDL
     * restituisce il render della finestra per permettere di effettuare operazioni esternamente alla classe
     * Nota: alcuni metodi delle altre classi potrebbero evere il valore restituito come parametro in ingresso
     */
    SDL_Renderer *externUpdate();
    /**
     * Imposta la finestra a schermo intero o non in funzione di state
     */
    void fulllScreen(bool state);
    /**
     * Restituisce la dimensione della finestra
     */
    Point windowSize();
};

#endif

#define GRAPH_CONTR 1
