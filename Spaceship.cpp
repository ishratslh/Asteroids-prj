//
// Created by Ishra on 22/10/2023.
//

#include "Spaceship.hpp"



Spaceship::Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle)
        : FlyingObject(x, y, size, xSpeed, ySpeed), angle(angle) {
    this -> warning = false;
    this -> shieldLevel = 1.0;
}

double Spaceship::GetAngle(){
    return this->angle;
}
bool Spaceship::GetWarning() {
    return std::chrono::system_clock::now() < invincibilityEndTime;
}

double Spaceship::GetShieldLevel() {
    return this->shieldLevel;
}

bool Spaceship::GetInvincible() {
    return std::chrono::system_clock::now() < invincibilityEndTime;
}

void Spaceship::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}
void Spaceship::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}
void Spaceship::SetAngle(double angle) {
    this->angle = angle;
}
void Spaceship::SetWarning(bool warning) {
    this->warning = warning;
}
void Spaceship::SetShieldLevel(double shieldLevel) {
    this->shieldLevel = shieldLevel;
}

void Spaceship::SpeedUp(double accelerationFactor){
    if((Spaceship::GetXSpeed()+accelerationFactor)>20||Spaceship::GetYSpeed()+accelerationFactor>20){

    }
    else{
        Spaceship::SetXSpeed(Spaceship::GetXSpeed()+accelerationFactor);
        Spaceship::SetYSpeed(Spaceship::GetYSpeed()+accelerationFactor);
    }
}

void Spaceship::SpeedDown(double decelerationFactor) {
    if((Spaceship::GetXSpeed()-decelerationFactor)<0||Spaceship::GetYSpeed()-decelerationFactor<0){

    }
    else{
        Spaceship::SetXSpeed(Spaceship::GetXSpeed()-decelerationFactor);
        Spaceship::SetYSpeed(Spaceship::GetYSpeed()-decelerationFactor);
    }

}

void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
}

void Spaceship::Move(double screenWidth, double screenHeight) {
    // mise à jour de la position
    double xspeed = Spaceship::GetXSpeed() * sin(FlyingObject::DegToRad(Spaceship::GetAngle()));
    double yspeed = Spaceship::GetYSpeed() * cos(FlyingObject::DegToRad(Spaceship::GetAngle()));

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
    else{
        x += xspeed;
        y += yspeed;
    }
}

void Spaceship::SetInvincibleFor(double duration) {
    invincibilityEndTime = std::chrono::system_clock::now() + std::chrono::seconds(static_cast<long>(duration));
}

std::string Spaceship::GetTypeName() const {
    return "Spaceship";
}

Spaceship::~Spaceship() = default;



