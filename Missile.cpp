//
// Created by Ishra on 05/10/2023.
//

#include "Missile.hpp"
#include <cmath>

Missile::Missile(double x, double y, double size, double speed, double angle)
: FlyingObject(x, y, size), speed(speed), angle(angle) {}

///////////////////////////////////////////////////////
// déplace selon les vitesses de déplacement de l'objet
// -------
// Renvoie : un booléen indiquant s'il y a sortie des limites de l'écran


bool Missile::Move(double screenWidth, double screenHeight){
    // déplace selon les vitesses de déplacement de l'objet
    x += speed * cos(angle);
    y += speed * sin(angle);

    // Renvoie : un booléen indiquant s'il y a sortie des limites de l'écran
    if (x < 0 || x > screenWidth || y < 0 || y > screenHeight) {
        return true;
    } else {
        return false;
    }
}

//double Missile::GetX(){ return x; }
//double Missile::GetY(){ return y; }
//double Missile::GetSize(){ return size; }

double Missile::GetXSpeed(){
    return speed * cos(angle);
}
double Missile::GetYSpeed(){
    return speed * sin(angle);
}
