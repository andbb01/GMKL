#include "PhysicsObject.h"

void PhysicsObject::addForce(float F, Point appPoint){
  double Icm, I_app, w;
  //Tutti i corpi vengono considerati proiezioni di parallelepipedi
  Icm = this->mass/12 * (this->position.h*this->position.h + this->position.w*this->position.w);
  //Teorema di Huygens-Steiner I_z = I_cm + M*d^2
  I_app = Icm + this->mass * appPoint.distance(this->position.v1);

  w = STD_DELAY*F * appPoint.distance(this->position.v1)/I_app ;

  this->objSetAngVelocity(w);
}

void PhysicsObject::addForce(float F, int x, int y){
  Point pos(x,y);
  this->addForce(F, pos);
}
void PhysicsObject::addForce(float Fx, float Fy){
  this->objSetVelocity(this->vel.x + Fx * STD_DELAY/this->mass,this->vel.y +  Fy * STD_DELAY/this->mass);
}

Point PhysicsObject::trackCollision(PhysicsObject other){
  Point collisionPoint(-1, -1);
  Point *ps;

  ps = position.vertexes();
  for (int i = 0; i < V_NUM; i++)
    if (other.position.contained(ps[i])){
      collisionPoint = ps[i];
      return collisionPoint;
    }

  return collisionPoint;
}
