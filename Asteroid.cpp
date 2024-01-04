//
// Created by Ishra on 20/09/2023.
//

#include "Asteroid.hpp"
#include <cmath>

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle)
        : FlyingObject(x, y, size, xSpeed, ySpeed), angle(angle) {}


double Asteroid::GetXSpeed() {
    return xSpeed;
}
double Asteroid::GetYSpeed() {
    return ySpeed;
}

double Asteroid::GetAngle() {
    return angle;
}

/*void Asteroid::Move() {
    x += xSpeed;
    y += ySpeed;
}*/

// move astéroide avec réentrée
void Asteroid::Move(double screenWidth, double screenHeight) {
    // mise à jour de la position

    double xspeed = Asteroid::GetXSpeed() * sin(FlyingObject::DegToRad(Asteroid::GetAngle()));
    double yspeed = Asteroid::GetYSpeed() * cos(FlyingObject::DegToRad(Asteroid::GetAngle()));

    if (this->x < 0) {
        x = screenWidth; // réapparaît à droite
    } else if (this->x > screenWidth) {
        x = 0; // réapparaît à gauche
    }

    if (y < 0) {
        y = screenHeight; // réapparaît en bas de l'écran
    } else if (y > screenHeight) {
        y = 0; // réapparaît en haut de l'écran
    }
    else{
        x += xspeed;
        y += yspeed;
    }
}

std::string Asteroid::GetTypeName() const {
    return "Asteroid";
}

