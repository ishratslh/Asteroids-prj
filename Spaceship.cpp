//
// Created by Ishra on 22/10/2023.
//

#include "Spaceship.hpp"
#include <cmath>


Spaceship::Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle)
        : FlyingObject(x, y, size, xSpeed, ySpeed), angle(angle) {}

double Spaceship::GetAngle(){
    return this->angle;
}
double Spaceship::GetXSpeed() const{
    return xSpeed * cos(angle);
}
double Spaceship::GetYSpeed() const{
    return ySpeed * sin(angle);
}

void Spaceship::SpeedUp(double accelerationFactor){
    double radian = this->angle * M_PI / 180;
    SetXSpeed(GetXSpeed() + accelerationFactor * cos(radian));
    SetYSpeed(GetYSpeed() + accelerationFactor * sin(radian));
}

void Spaceship::SpeedDown(double decelerationFactor) {
    double radian = this->angle * M_PI / 180;
    SetXSpeed(GetXSpeed() - decelerationFactor * cos(radian));
    SetYSpeed(GetYSpeed() - decelerationFactor * sin(radian));
}

void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
}

void Spaceship::Move(double screenWidth, double screenHeight) {
    // mise à jour de la position
    x += GetXSpeed();
    y += GetYSpeed();

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


