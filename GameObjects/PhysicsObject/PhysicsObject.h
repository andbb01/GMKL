#include "../GameObject.h"

#ifndef PHYOBJ_CONTR

class PhysicsObject : public GameObject{
  private:
    float mass;
  public:
    PhysicsObject(int x, int y, int w, int h, float m) : GameObject(x, y, w, h){
      this->mass = m;
    }
    void addForce(float Fx, float Fy);
    void addForce(float F, Point app_point);
    void addForce(float F, int x, int y);
    Point trackCollision(PhysicsObject other);
};

#endif

#define PHYOBJ_CONTR 1
