//
// Created by Ishra on 22/10/2023.
//

#include "Spaceship.hpp"
#include <cmath>
#include <iostream>


Spaceship::Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle)
        : FlyingObject(x, y, size, xSpeed, ySpeed), angle(angle) {
    this -> warning = false;
    this -> shieldLevel = 1.0;

}

double Spaceship::GetAngle(){
    return this->angle;
}
double Spaceship::GetWarning() {
    return this->warning;
}

double Spaceship::GetShieldLevel() {
    return this->shieldLevel;
}

void Spaceship::SpeedUp(double accelerationFactor){
    double radian = (angle-90) * M_PI / 180;
    double newXSpeed = GetXSpeed() + accelerationFactor * cos(radian);
    double newYSpeed = GetYSpeed() + accelerationFactor * sin(radian);
    //std::cout << "SpeedUp: newXSpeed = " << newXSpeed << ", newYSpeed = " << newYSpeed << std::endl;
    SetXSpeed(newXSpeed);
    SetYSpeed(newYSpeed);
}

void Spaceship::SpeedDown(double decelerationFactor) {
    double radian = (angle-90) * M_PI / 180;
    double newXSpeed = GetXSpeed() - decelerationFactor * cos(radian);
    double newYSpeed = GetYSpeed() - decelerationFactor * sin(radian);

    //std::cout << "SpeedDown: newXSpeed = " << newXSpeed << ", newYSpeed = " << newYSpeed << std::endl;

    SetXSpeed(newXSpeed);
    SetYSpeed(newYSpeed);
}

void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
}

void Spaceship::Move(double screenWidth, double screenHeight) {
    // mise à jour de la position
    x += GetXSpeed();
    y += GetYSpeed();
    //std::cout << "Move: x = " << x << ", y = " << y << std::endl;


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

std::string Spaceship::GetTypeName() const {
    return "Spaceship";
}

Spaceship::~Spaceship() = default;



