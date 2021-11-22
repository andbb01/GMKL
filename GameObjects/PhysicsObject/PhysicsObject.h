#include "../GameObject.h"

#ifndef PHYOBJ_CONTR

/**
 * Estensione della classe GameObject per la gestione di alcune opzioni "fisiche"
 * <strong>Nota:</strong> si utilizza deltat = 20 ms per una quantizzazione della
 * grafica di 120 ms a prescindere dal ritardo effettivo della sync grafica
 */


class PhysicsObject : public GameObject{
  private:
    /**
     * Massa inerziale dell'oggetto fisico
     */
    float mass;
  public:
    /**
     * Estende il costruttore di GameObject aggiungendo il parametro massa
     */
    PhysicsObject(int x, int y, int w, int h, float m) : GameObject(x, y, w, h){
      this->mass = m;
    }
    /**
     * Applica una forza al centro di massa dell'oggetto generando un accelerazione che farà variare la velocità in un intervallo deltat
     */
    void addForce(float Fx, float Fy);
    /**
     * Aggiunge una forza in app_point generando una rotazione
     * <strong>Nota: </strong> il punto di applicazione è misurato da un sistema di riferimento solidale al centro di massa (baricentro)
     */
    void addForce(float F, Point app_point);
    /**
     * Uguale ad addForce(float F, Point app_point) con app_point = (x,y)
     */
    void addForce(float F, int x, int y);
    /**
     * Verifica se l'oggetto this è entrato in collisione con l'oggetto other, se è vero restituisce il punto di collisione più vicino altrimenti
     * restituisce un punto con x e y negativi (fuori del piano considerato)
     */
    Point trackCollision(PhysicsObject other);
};

#endif

#define PHYOBJ_CONTR 1
