//
// Created by Ishra on 20/09/2023.
//

#include "FlyingObject.hpp"
#include <cmath>

FlyingObject::FlyingObject(double x, double y, double size)
        : x(x), y(y), size(size) {}

// Getters
double FlyingObject::GetX() {
    return this->x;
}
double FlyingObject::GetY() {
    return this->y;
}
double FlyingObject::GetSize() {
    return this->size;
}

// Setters
void FlyingObject::SetX(double x) {
    this->x = x;
}
void FlyingObject::SetY(double y) {
    this->y = y;
}
void FlyingObject::SetSize(double size) {
    this->size = size;
}


/////////////////////////////
// Détermination de collision
// calcul basé sur l'hypothèse que les objets sont sphériques
// -------
// * o1, o2 : les deux objets à tester
// -------
// Renvoie : true si les deux objets se touchent, false sinon
bool FlyingObject::Collide(FlyingObject o1, FlyingObject o2) {
    double dx = o1.GetX() - o2.GetX();
    double dy = o1.GetY() - o2.GetY();
    double distance = sqrt(dx * dx + dy * dy);
    return distance < o1.GetSize()/2 + o2.GetSize()/2;
}



