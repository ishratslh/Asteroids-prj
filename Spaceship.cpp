//
// Created by Ishra on 22/10/2023.
//
#include "Spaceship.hpp"

Spaceship::Spaceship(double x, double y, double size, double xSpeed, double ySpeed, double angle)
        : FlyingObject(x, y, size, xSpeed, ySpeed), angle(angle) {
    this -> warning = false;
    this -> shieldLevel = 1.0;
}

//____________________________________Getters and Setters____________________________________
double Spaceship::GetAngle(){
    return this->angle;
}
bool Spaceship::GetWarning() { // Renvoie un booléen indiquant si le vaisseau est en warning ou non
    return std::chrono::system_clock::now() < invincibilityEndTime;
}
double Spaceship::GetShieldLevel() { //Renvoie le niveau de bouclier du vaisseau
    return this->shieldLevel;
}
bool Spaceship::GetInvincible() { // Renvoie un booléen indiquant si le vaisseau est invincible ou non
    return std::chrono::system_clock::now() < invincibilityEndTime;
}
std::string Spaceship::GetTypeName() const {
    return "Spaceship";
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
void Spaceship::SetInvincibleFor(double duration) {
    invincibilityEndTime = std::chrono::system_clock::now() + std::chrono::seconds(static_cast<long>(duration));
}

//____________________________________Speed Up/Down____________________________________
void Spaceship::SpeedUp(double accelerationFactor){
    if((Spaceship::GetXSpeed()+accelerationFactor)>20||Spaceship::GetYSpeed()+accelerationFactor>20){
        //Si la vitesse est supérieure à 20, on n'augmente pas plus la vitesse du vaisseau que ça
    }
    else{
        Spaceship::SetXSpeed(Spaceship::GetXSpeed()+accelerationFactor);
        Spaceship::SetYSpeed(Spaceship::GetYSpeed()+accelerationFactor);
    }
}

void Spaceship::SpeedDown(double decelerationFactor) {
    if((Spaceship::GetXSpeed()-decelerationFactor)<-20||Spaceship::GetYSpeed()-decelerationFactor<-20){
        //Si la vitesse est inférieure à -20, on ne diminue pas plus la vitesse du vaisseau que ça
        //Permet un recul du vaisseau
    }
    else{
        Spaceship::SetXSpeed(Spaceship::GetXSpeed()-decelerationFactor);
        Spaceship::SetYSpeed(Spaceship::GetYSpeed()-decelerationFactor);
    }
}

//____________________________________Rotate____________________________________
void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
}

//____________________________________Move____________________________________
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

Spaceship::~Spaceship() = default;



