//
// Created by Ishra on 20/09/2023.
//

#include "Asteroid.hpp"

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle, int nbExplosions)
        : FlyingObject(x, y, size, xSpeed, ySpeed), angle(angle), nbExplosionsRestant(nbExplosions) {}

//____________________________________Getters and Setters____________________________________
double Asteroid::GetXSpeed() {
    return xSpeed;
}
double Asteroid::GetYSpeed() {
    return ySpeed;
}
double Asteroid::GetAngle() {
    return angle;
}
double Asteroid::GetNbExplosionsRestant() {
    return nbExplosionsRestant;
}
std::string Asteroid::GetTypeName() const {
    return "Asteroid";
}
void Asteroid::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}
void Asteroid::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}
void Asteroid::SetAngle(double angle) {
    this->angle = angle;
}
void Asteroid::SetNbExplosionsRestant(int nbExplosionsRestant) {
    this->nbExplosionsRestant = nbExplosionsRestant;
}

//____________________________________Move____________________________________

void Asteroid::Move() {
    x += xSpeed;
    y += ySpeed;
}

// move asteroide avec réentrée
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

//____________________________________Explode____________________________________
Asteroid *Asteroid::Explode(double speed, double angle) {
    if(this->nbExplosionsRestant>0){
        //si un missile touche un asteroide, celui-ci se divise en 2 et nbExplosionsLeft est décrémenté
        double newTaille = Asteroid::GetSize()/2; //Taille plus petite
        Asteroid* newAsteroid = new Asteroid(Asteroid::GetX(), Asteroid::GetY(), newTaille, Asteroid::GetXSpeed(), Asteroid::GetYSpeed(), angle,nbExplosionsRestant-2);
        this->nbExplosionsRestant--;
        return newAsteroid;
    }
    else{
        return nullptr;
    }
}

