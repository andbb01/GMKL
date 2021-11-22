#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Types.h"

#ifndef GRAPH_CONTR

class GameObject;

class Graphics{
  private:
    SDL_Window *win;
    SDL_Renderer *ren;
    Point size;
    int delay;
  public:
    Graphics();
    Graphics(int delay);
    void createWindow(int w, int h);
    void setBackgroundColor(int r, int g, int b);
    void update();
    void setDrawingColor(int r, int g, int b);
    void drawPoint(Point p);
    void drawRect(Rect r);
    void drawObject(GameObject obj);
    void drawObject(GameObject obj, int r, int g, int b);
    void setObjSprite(const char *fileName, GameObject *obj);
    SDL_Renderer *externUpdate();
    ~Graphics();
};

#endif

#define GRAPH_CONTR 1
