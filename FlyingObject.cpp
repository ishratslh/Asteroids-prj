//
// Created by Ishra on 20/09/2023.
//

#include "FlyingObject.hpp"

FlyingObject::FlyingObject(double x, double y, double size, double xSpeed, double ySpeed)
        : x(x), y(y), size(size), xSpeed(xSpeed), ySpeed(ySpeed) {}

//____________________________________Getters and Setters____________________________________
double FlyingObject::GetX() {
    return this->x;
}
double FlyingObject::GetY() {
    return this->y;
}
double FlyingObject::GetSize() {
    return this->size;
}
double FlyingObject::GetXSpeed() {
    return xSpeed;
}
double FlyingObject::GetYSpeed() {
    return ySpeed;
}
void FlyingObject::SetX(double x) {
    this->x = x;
}
void FlyingObject::SetY(double y) {
    this->y = y;
}
void FlyingObject::SetSize(double size) {
    this->size = size;
}

void FlyingObject::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}
void FlyingObject::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

std::string FlyingObject::GetTypeName() const {
    return "FlyingObject";
}

//____________________________________Move____________________________________
void FlyingObject::Move() {
    this->x += this->xSpeed;
    this->y += this->ySpeed;
}
void FlyingObject::Move(double screenWidth, double screenHeight) {
    // mise à jour de la position
    this->x += this->xSpeed;
    this->y += this->ySpeed;

    if (x < 0) {
        x = screenWidth; // réapparaît à droite
    } else if (x > screenWidth) {
        x = 0; // réapparaît à gauche
    }

    if (y < 0) {
        y = screenHeight; // réapparaît en bas de l'écran
    } else if (y > screenHeight) {
        y = 0; // réapparaît en haut de l'écran
    }
}

//____________________________________Collide____________________________________
// adresses (sans MVC - test)
bool FlyingObject::Collide(FlyingObject &o1, FlyingObject &o2) {
    double dx = o1.GetX() - o2.GetX();
    double dy = o1.GetY() - o2.GetY();
    double distance = sqrt(dx * dx + dy * dy);
    return distance < o1.GetSize()/2 + o2.GetSize()/2;
}
// pointeurs (avec MVC)
bool FlyingObject::Collide(FlyingObject *o1,FlyingObject *o2) {
    // Calcul de la distance entre els 2 centres des objets
    double distance = sqrt(pow(o2->x - o1->x, 2) + pow(o2->y - o1->y, 2));
    double rayon1 = o1->size/2;
    double rayon2 = o2->size/2;

    // calculer si la distance est sup ou inf a la somme de leurs rayons
    if (distance <= rayon1 + rayon2) {
        return true;
    } else {
        return false;
    }
}

//____________________________________DegToRad____________________________________
double FlyingObject::DegToRad(double angle) {
    return ((M_PI)*(180-angle))/180;
}



