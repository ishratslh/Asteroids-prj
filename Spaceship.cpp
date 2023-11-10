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
    double radian = angle * M_PI / 180;
    double xSpeed = accelerationFactor * cos(radian);
    double ySpeed = accelerationFactor * sin(radian);
    SetXSpeed(GetXSpeed() + xSpeed);
    SetYSpeed(GetYSpeed() + ySpeed);
}

void Spaceship::SpeedDown(double decelerationFactor) {
    double radian = angle * M_PI / 180;
    double xSpeed = decelerationFactor * cos(angle);
    double ySpeed = decelerationFactor * sin(angle);
    SetXSpeed(GetXSpeed() - xSpeed);
    SetYSpeed(GetYSpeed() - ySpeed);
}

void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
}

